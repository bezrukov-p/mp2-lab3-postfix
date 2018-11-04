#include "postfix.h"
#include "stack.h"
#include <string>

using namespace std;

bool TPostfix::IsOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return true;
	else
		return false;
}

int TPostfix::Priority(char a, char b)//1 - a приоритетнее b,0 - одинаковы,-1 - b приоритетнее
{
	if ((a == '*' || a == '/') && (b == '*' || b == '/'))
		return 0;
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	if ((a == '+' || a == '-') && (b == '+' || b == '-'))
		return 0;
	throw "not operation";
}

double TPostfix::Operation(double left, double right, char c)
{
	switch (c)
	{
	case '+':
	{
		return left + right;
	}
	case '-':
	{
		return left - right;
	}
	case '*':
	{
		return left * right;
	}
	case '/':
	{
		if (right == 0)
			throw 0;
		return left / right;
	}
	default:
		throw "invalid operation";
	}
}

bool TPostfix::CheckInfix()//пустой, первый или последний операторы,два подряд оператора,нет операторов
{
	if (infix.empty())
		return false;
	else
		if (IsOperator(infix[0]) || IsOperator(infix[infix.size() - 1]))
			return false;
	for (int i = 0; i < infix.size() - 1; i++)
	{
		if (IsOperator(infix[i]) && IsOperator(infix[i + 1]))
			return false;
	}
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == ' ')
			return false;
		if (infix[i] == '(')
			count1++;
		if (infix[i] == ')')
			count2++;
		if (IsOperator(infix[i]))
			count3++;
	}
	if ((count1 != count2) || count3 == 0)
		return false;
	return true;
}

string TPostfix::ToPostfix()
{
	TStack<char> opers(infix.size());
	for (int i = 0; i < infix.size(); i++)
	{
		if (!IsOperator(infix[i]) && infix[i] != '(' && infix[i] != ')')
		{
			int j = i;
			while (!IsOperator(infix[j]) && j != infix.size() && infix[j] != ')')
			{
				postfix += infix[j];
				j++;
			}
			i = j - 1;
			postfix += ',';
		}
		else
			if (opers.IsEmpty())
				opers.Push(infix[i]);
			else
				if (opers.Top() == '(')
					opers.Push(infix[i]);
				else
				 if (infix[i] == '(')
					opers.Push(infix[i]);
				else
					if (infix[i] == ')')
					{
						while (opers.Top() != '(')
						{
							postfix += opers.Pop();
							postfix += ',';
						}
						opers.Pop();
					}
					else
					if (Priority(infix[i], opers.Top()) == 1)
						opers.Push(infix[i]);
					else
							{
								while ((opers.Top() != '('))
								{
									if (Priority(infix[i], opers.Top()) == 1)
										break;
									postfix += opers.Pop();
									postfix += ',';
									if (opers.IsEmpty())
										break;
								}
								opers.Push(infix[i]);
							}
	}
	while (!opers.IsEmpty())
	{
		postfix += opers.Pop();
		postfix += ',';
	}
	return postfix;
}

double TPostfix::Calculate()//элементы разделяются запятыми
{
	ToPostfix();
	TStack<double> nums(infix.size());
	for (int i = 0; i < postfix.size(); i++)
	{
		if (!IsOperator(postfix[i]))
		{
			string doub;
			doub += postfix[i];
			int j = i + 1;// добавляем в doub и переходим к следующему эл-ту
			while (postfix[j] != ',')
			{
				doub += postfix[j];
				j++;
			}
			nums.Push(atof(doub.c_str()));// atof из string в double(НЕ РАБОТАЕТ(ВОЗВРАЩАЕТ ТОЛЬКО ЦЕЛУЮ ЧАСТЬ))
			i = j;//на место ','
		}
		else
		{
			nums.Push(Operation(nums.Pop(), nums.Pop(), postfix[i]));
			i++;//на место ','
		}
	}
	return nums.Top();
}

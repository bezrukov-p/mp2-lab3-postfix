#include "postfix.h"
#include "stack.h"

bool TPostfix::IsOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')')
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
}

string TPostfix::ToPostfix()
{
	TStack<char> opers(infix.size());
	for (int i = 0; i < infix.size(); i++)
	{
		if (!IsOperator(infix[i]))
			postfix += infix[i];
		else
			if (opers.IsEmpty())
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
						}
						opers.Pop();
					}
					else
						if (Priority(infix[i], opers.Top()) == 1)
							opers.Push(infix[i]);
						else
						{
							while ((opers.Top() != '(') || (Priority(infix[i], opers.Top()) == 1))
							{
								postfix += opers.Pop();
							}
							opers.Push(infix[i]);
						}
	}
	while (!opers.IsEmpty())
	{
		postfix += opers.Pop();
	}
	return postfix;
}

double TPostfix::Calculate()
{
  return 0;
}

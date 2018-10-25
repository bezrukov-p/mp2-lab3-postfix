#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
	string infix;
	string postfix;
	bool IsOperator(char op);
	int Priority(char a, char b);
public:
	TPostfix(string str = "a+b")
	{
		infix = str;
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif

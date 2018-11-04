#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	int item = 0;
  string expression;
  cout << "1.ToPostfix" << endl;
  cout << "2.Calculate" << endl;
  cout << endl;
  while (true)
  {
	  cout << "Enter menu item:";
	  cin >> item;
	  switch (item)
	  {
	  case 1:
	  {
		  cout << "Have to be entered without spaces." << endl;
		  cout << "Enter an arithmetic expression: ";
		  cin >> expression;
		  TPostfix postfix(expression);
		  if (!postfix.CheckInfix())
		  {
			  cout << "Invalid expression" << endl << endl;
			  break;
		  }
		  cout << "Arithmetic expression: " << postfix.GetInfix() << endl;
		  postfix.ToPostfix();
		  cout << "Postfix form: " << postfix.GetPostfix() << endl << endl;
		  break;
	  }
	  case 2:
	  {
		  cout << "Have to be entered without spaces." << endl;
		  cout << "Enter an arithmetic expression: ";
		  cin >> expression;
		  TPostfix postfix(expression);
		  if (!postfix.CheckInfix())
		  {
			  cout << "Invalid expression" << endl << endl;
			  break;
		  }
		  cout << "Arithmetic expression: " << postfix.GetInfix() << endl;
		  postfix.ToPostfix();
		  cout << "Postfix form: " << postfix.GetPostfix() << endl;
		  cout << "Result: " << postfix.Calculate() << endl << endl;
		  break;
	  }
	  default:
		  break;
	  }
  }
  return 0;
}

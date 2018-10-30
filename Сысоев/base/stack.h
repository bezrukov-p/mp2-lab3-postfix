#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

const int MaxStackSize = 100;

template <class T>
class TStack
{
	T *pMem;
	int size;
	int top;
public:
	TStack(int _size)
	{
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw size;
		pMem = new T[size];
	}

	TStack(TStack &s)
	{
		size = s.size;
		top = s.top;
		pMem = new T[size];
		for (int i = 0; i < top + 1; i++)
			pMem[i] = s.pMem[i];
	}

	bool IsEmpty()
	{
		return (top == -1);
	}

	bool IsFull()
	{
		return (top == (size - 1));
	}

	T Pop() //взять
	{
		if (!IsEmpty())
			return pMem[top--];
		else
			throw "Empty";
	}

	T Top()//посмотреть
	{
		if (!IsEmpty())
			return pMem[top];
		else
			throw "Empty";
	}

	void Push(T v)//положить
	{
		if (!IsFull())
			pMem[++top] = v;
		else
			throw "Empty";
	}

	~TStack()
	{
		delete[] pMem;
	}
};

#endif

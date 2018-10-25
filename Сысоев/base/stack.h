#ifndef __STACK_H__
#define __STACK_H__

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

	bool IsEmpty()
	{
		return (top == -1);
	}

	bool IsFull()
	{
		return (top == (size - 1));
	}

	T Pop()
	{
		if (!IsEmpty())
			return pMem[top--];
		else
			throw "Empty";
		T a;
		return a;
	}

	T Top()
	{
		if (!IsEmpty())
			return pMem[top];
		else
			throw "Empty";
		T a;
		return a;
	}

	void Push(T v)
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

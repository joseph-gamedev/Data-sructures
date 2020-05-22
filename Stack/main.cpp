#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> testStack;
	testStack.Push(6);
	testStack.Push(7);
	testStack.Push(8);
	testStack.Push(9);
	testStack.Push(10);
	testStack.Pop();
	testStack.Display(); 

	std::cin.get();
}
#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> testQueue;
	testQueue.Enqueue(91);
	testQueue.Enqueue(92);
	testQueue.Enqueue(93);
	testQueue.Enqueue(94);
	testQueue.Dequeue();
	testQueue.Display();

	std::cin.get();
}
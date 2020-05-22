#include "LinkedList.h"

int main()
{
	LinkedList<int> list;
	list.InsertAtFront(5);
	list.InsertAtFront(6);
	list.InsertAtFront(7);
	list.InsertAtBack(4);

	list.Display();

	std::cin.get();
}
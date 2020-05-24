#include <iostream>
#include "Tree.h"

int main()
{
	Tree<int> testTree;
	testTree.InsertNode(32);
	testTree.InsertNode(12);
	testTree.InsertNode(29);
	testTree.InsertNode(4);
	testTree.InsertNode(16);
	testTree.InsertNode(35);
	testTree.InsertNode(50);

	testTree.BeginPreOrderTraversal();
	testTree.BeginInOrderTraversal();
	testTree.BeginPostOrderTraversal();
	
	bool testStatus = testTree.Contains(35); 
	if (testStatus)
	{
		std::cout << "search found";
	}
	else
	{
		std::cout << "search not found";
	}

	std::cin.get();
}
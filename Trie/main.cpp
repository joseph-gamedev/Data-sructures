
#include <iostream>
#include <array>
#include "Trie.h"

std::array<std::string, 10> g_WordList = { "Apple", "Orange", "Cat", "Common", "Rat",
										   "Computer", "Keyboard", "mouse", "Fruit", 
										  "Vegetable" 
										 };

void Search(const std::string& key , Trie& trie)
{
	bool status = trie.Search(key);
	std::string info = "match Found";
	if (!status)
	{
		info = "match not Found";
	}
	std::cout << "key '" + key + "' search: " << info << std::endl;
}

int main()
{
	Trie testTrie;

	for (auto& word : g_WordList)
	{
		testTrie.Insert(word);
	}

	Search("Computer", testTrie);
	Search("Mango", testTrie);
	Search("Apple", testTrie);
	Search("Magic", testTrie);

	std::cin.get();
}
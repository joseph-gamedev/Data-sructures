#include "Trie.h"
#include <iostream>


Trie::Trie()
	:m_RootNode(new Node())
{

}

void Trie::Insert(const std::string& key)
{
	Node* node = m_RootNode;
	for (auto& letter: key)
	{
		node = node->Insert(letter);		
	}
	if (node)
	{
		node->m_IsEndNode = true;
	}
}

void Trie::Remove(const std::string& key)
{
}

bool Trie::Search(const std::string& key)
{
	Node* node = m_RootNode;
	for (auto& letter : key)
	{
		node = node->GetNode(letter);
		if (!node)
		{
			return false;
			break;
		}
	}
	if (node->IsEndNode())
	{
		return true;
	}

	return false;
}

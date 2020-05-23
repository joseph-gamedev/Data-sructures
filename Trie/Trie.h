#pragma once

#include "Node.h"

class Trie
{
public:
	Trie();
	~Trie();
	void Insert(const std::string& key);
	void Remove(const std::string& key);
	bool Search(const std::string& key);
private:
	Node* m_RootNode;
};

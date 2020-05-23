#pragma once 

#include <unordered_map>

class Trie;

class Node
{
	friend class Trie;
public:
	~Node();
	Node* Insert(char letter);
	Node* GetNode(char letter);
	bool IsEndNode() const;

private:

	bool m_IsEndNode = false;
	std::unordered_map<char, Node*> m_ChildNodes;
};

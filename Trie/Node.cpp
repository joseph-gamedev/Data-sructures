#include "Node.h"

Node* Node::Insert(char letter)
{
	Node* node = new Node();
	m_ChildNodes[letter] = node;
	return node;
}

Node* Node::GetNode(char letter)
{
	return m_ChildNodes[letter];
}

bool Node::IsEndNode() const
{
	return m_IsEndNode;
}

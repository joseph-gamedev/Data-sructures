#include "Node.h"

Node::~Node()
{
	for (size_t count = 0; count < m_ChildNodes.size(); count++)
	{
		if (m_ChildNodes[count])
		{
			delete m_ChildNodes[count];
			m_ChildNodes[count] = nullptr;
		}
	}
	m_ChildNodes.clear();
}

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


#pragma once

#include "Node.h"
#include <iostream>

template< typename NodeType>
class Stack
{
public:
	~Stack();
	void Push(const NodeType& nodeInfo);
	void Pop();

	bool IsEmpty();
	void Clear();
	void Display();

private:
	Node<NodeType>* m_TopNode;

	Node<NodeType>* NewNode(const NodeType& nodeInfo);
};

template<typename NodeType>
inline Stack<NodeType>::~Stack()
{
	Clear();
}

template<typename NodeType>
inline void Stack<NodeType>::Push(const NodeType& nodeInfo)
{
	Node<NodeType>* newPtr{ NewNode(nodeInfo) };
	if (IsEmpty())
	{
		m_TopNode = newPtr;
	}
	else
	{
		newPtr->m_NextPtr = m_TopNode;
		m_TopNode = newPtr;
	}
}

template<typename NodeType>
inline void Stack<NodeType>::Pop()
{
	if (!IsEmpty())
	{
		Node<NodeType>* tempTopNode{ m_TopNode };

		if (m_TopNode->m_NextPtr == nullptr)
		{
			m_TopNode = nullptr;
		}
		else
		{
			m_TopNode = m_TopNode->m_NextPtr;
		}
		delete tempTopNode;
	}
}

template<typename NodeType>
inline bool Stack<NodeType>::IsEmpty()
{
	return m_TopNode == nullptr;
}

template<typename NodeType>
inline void Stack<NodeType>::Clear()
{
	if (IsEmpty())
	{
		return;
	}

	Node<NodeType>* m_CurrentPtr{ m_TopNode };
	Node<NodeType>* m_PreviousPtr{ nullptr };
	while (m_CurrentPtr)
	{
		m_PreviousPtr = m_CurrentPtr;
		m_CurrentPtr = m_CurrentPtr->m_NextPtr;
		if (m_PreviousPtr)
		{
			delete m_PreviousPtr;
		}
	}
}

template<typename NodeType>
inline void Stack<NodeType>::Display()
{
	if (!IsEmpty())
	{
		Node<NodeType>* m_CurrentPtr{ m_TopNode };
		while (m_CurrentPtr)
		{
			std::cout << m_CurrentPtr->GetData() << std::endl;
			m_CurrentPtr = m_CurrentPtr->m_NextPtr;
		}
	}
}

template<typename NodeType>
inline Node<NodeType>* Stack<NodeType>::NewNode(const NodeType& nodeInfo)
{
	return new Node<NodeType>{ nodeInfo };
}

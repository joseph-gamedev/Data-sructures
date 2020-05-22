#pragma once

#include "Node.h"
#include <iostream>

template<typename NodeType>
class LinkedList
{
public:
	~LinkedList();
	void InsertAtFront(const NodeType& nodeInfo);
	void InsertAtBack(const NodeType& nodeInfo);
	void RemoveFromFront();
	void RemoveFromBack();

	bool IsEmpty();
	void Clear();

	void Display();

private:
	Node<NodeType>* m_HeadNode;
	Node<NodeType>* m_TailNode;

	Node<NodeType>* NewNode(const NodeType& nodeInfo);

};

template<typename NodeType>
inline LinkedList<NodeType>::~LinkedList()
{	
	Clear();
}

template<typename NodeType>
inline void LinkedList<NodeType>::InsertAtFront(const NodeType& nodeInfo)
{
	Node<NodeType>* newPtr{ NewNode(nodeInfo) };

	if (IsEmpty())
	{
		m_HeadNode = m_TailNode = newPtr;
	}
	else
	{
		newPtr->m_NextPtr = m_HeadNode;
		m_HeadNode = newPtr;
	}
}

template<typename NodeType>
inline void LinkedList<NodeType>::InsertAtBack(const NodeType& nodeInfo)
{
	Node<NodeType>* newPtr{ NewNode(nodeInfo) };
	if (IsEmpty())
	{
		m_HeadNode = m_TailNode = newPtr;
	}
	else
	{
		m_TailNode->m_NextPtr = newPtr;
		m_TailNode = newPtr;
	}
}

template<typename NodeType>
inline void LinkedList<NodeType>::RemoveFromFront()
{
	if (!IsEmpty())
	{
		Node<NodeType>* tempHeadNode{ m_HeadNode };

		if (m_HeadNode == m_TailNode)
		{
			m_HeadNode = m_TailNode = nullptr;
		}
		else
		{
			m_HeadNode = m_HeadNode->m_NextPtr;
		}
		delete tempHeadNode;	
	}
}

template<typename NodeType>
inline void LinkedList<NodeType>::RemoveFromBack()
{
	if (!IsEmpty())
	{
		Node<NodeType>* tempTailNode{ m_TailNode };

		if (m_HeadNode == m_TailNode)
		{
			m_HeadNode = m_TailNode = nullptr;
		}
		else
		{
			//iterate from beginning 
			Node<NodeType>* CurrentNode{ m_HeadNode };
			while (CurrentNode->m_NextPtr != m_TailNode)
			{
				CurrentNode = CurrentNode->m_NextPtr;
			}
			m_TailNode = CurrentNode;
			CurrentNode->m_NextPtr = nullptr;
			
		}
		delete tempTailNode;
	}
}

template<typename NodeType>
inline bool LinkedList<NodeType>::IsEmpty()
{
	return m_HeadNode == nullptr;
}

template<typename NodeType>
inline void LinkedList<NodeType>::Clear()
{
	if (IsEmpty())
	{
		return;
	}

	Node<NodeType>* m_CurrentPtr{ m_HeadNode };
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
inline void LinkedList<NodeType>::Display()
{
	if (!IsEmpty())
	{
		Node<NodeType>* m_CurrentPtr{ m_HeadNode };
		while (m_CurrentPtr)
		{
			std::cout << m_CurrentPtr->GetData() << " ";
			m_CurrentPtr = m_CurrentPtr->m_NextPtr;
		}
	}
}

template<typename NodeType>
inline Node<NodeType>* LinkedList<NodeType>::NewNode(const NodeType& nodeInfo)
{
	return new Node<NodeType>{ nodeInfo };
}

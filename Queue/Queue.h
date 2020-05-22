#pragma once

#include "Node.h"

template<typename NodeType>
class Queue
{
public:
	~Queue();
	void Enqueue(const NodeType& nodeInfo);
	void Dequeue();

	bool IsEmpty();
	void Clear();

	void Display();

private:
	Node<NodeType>* m_HeadNode;
	Node<NodeType>* m_TailNode;

	Node<NodeType>* NewNode(const NodeType& nodeInfo);
};

template<typename NodeType>
inline Queue<NodeType>::~Queue()
{
	Clear();
}

template<typename NodeType>
inline void Queue<NodeType>::Enqueue(const NodeType& nodeInfo)
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
inline void Queue<NodeType>::Dequeue()
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
inline bool Queue<NodeType>::IsEmpty()
{
	return m_HeadNode == nullptr;
}

template<typename NodeType>
inline void Queue<NodeType>::Clear()
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
inline void Queue<NodeType>::Display()
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
inline Node<NodeType>* Queue<NodeType>::NewNode(const NodeType& nodeInfo)
{
	return new Node<NodeType>{ nodeInfo };
}

#pragma once

#include "Node.h"
#include <iostream>

template<typename NodeType>
class Tree
{
public:
	void InsertNode(const NodeType& nodeInfo);
	void BeginPreOrderTraversal() const;
	void BeginInOrderTraversal() const;
	void BeginPostOrderTraversal() const;

private:
	void InsertNode(Node<NodeType>** nodePtr, const NodeType& nodeInfo);
	void TraversePreOrder(Node<NodeType>* nodePtr) const;
	void TraverseInOrder(Node<NodeType>* nodePtr) const;
	void TraversePostOrder(Node<NodeType>* nodePtr) const;
	Node<NodeType>* NewNode(const NodeType& nodeInfo);

private:
	Node<NodeType>* m_RootNode{nullptr};
};

template<typename NodeType>
inline void Tree<NodeType>::InsertNode(const NodeType& nodeInfo)
{
	InsertNode(&m_RootNode, nodeInfo);
}

template<typename NodeType>
inline void Tree<NodeType>::BeginPreOrderTraversal() const
{
	std::cout << "PreOrderTraversal : ";
	TraversePreOrder(m_RootNode);
	std::cout << std::endl;
}

template<typename NodeType>
inline void Tree<NodeType>::BeginInOrderTraversal() const
{
	std::cout << "InOrderTraversal : ";
	TraverseInOrder(m_RootNode);
	std::cout << std::endl;
}

template<typename NodeType>
inline void Tree<NodeType>::BeginPostOrderTraversal() const
{
	std::cout << "PostOrderTraversal : ";
	TraversePostOrder(m_RootNode);
	std::cout << std::endl;
}

template<typename NodeType>
inline void Tree<NodeType>::InsertNode(Node<NodeType>** nodePtr, const NodeType& nodeInfo)
{
	if (!*nodePtr)
	{
		*nodePtr = NewNode(nodeInfo);
	}
	else
	{
		if (nodeInfo != (*nodePtr)->GetData())
		{
			if (nodeInfo < (*nodePtr)->GetData())
			{
				InsertNode(&((*nodePtr)->m_LeftNodePtr), nodeInfo);
			}
			else
			{
				InsertNode(&((*nodePtr)->m_RightNodePtr), nodeInfo);
			}
		}
	}
}

template<typename NodeType>
inline void Tree<NodeType>::TraversePreOrder(Node<NodeType>* nodePtr) const
{
	if (nodePtr)
	{
		std::cout << nodePtr->GetData() << " ";
		TraversePreOrder(nodePtr->m_LeftNodePtr);
		TraversePreOrder(nodePtr->m_RightNodePtr);
	}
}

template<typename NodeType>
inline void Tree<NodeType>::TraverseInOrder(Node<NodeType>* nodePtr) const
{
	if (nodePtr)
	{
		TraverseInOrder(nodePtr->m_LeftNodePtr);
		std::cout << nodePtr->GetData() << " ";
		TraverseInOrder(nodePtr->m_RightNodePtr);
	}
}

template<typename NodeType>
inline void Tree<NodeType>::TraversePostOrder(Node<NodeType>* nodePtr) const
{
	if (nodePtr)
	{
		TraversePostOrder(nodePtr->m_LeftNodePtr);
		TraversePostOrder(nodePtr->m_RightNodePtr);
		std::cout << nodePtr->GetData() << " ";
	}
}

template<typename NodeType>
inline Node<NodeType>* Tree<NodeType>::NewNode(const NodeType& nodeInfo)
{
	return  new Node<NodeType>{ nodeInfo };
}

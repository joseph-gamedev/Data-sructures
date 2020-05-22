#pragma once 

template <typename NodeType > class Stack;

template <typename NodeType >
class Node
{
	friend class Stack<NodeType>;
public:
	Node(const NodeType& nodeInfo);

	NodeType GetData() const;

private:
	NodeType m_Data;
	Node<NodeType> *m_NextPtr;
};

template<typename NodeType>
inline Node<NodeType>::Node(const NodeType& nodeInfo)
	: m_Data(nodeInfo)
	, m_NextPtr(nullptr)
{
}

template<typename NodeType>
inline NodeType Node<NodeType>::GetData() const
{
	return m_Data;
}

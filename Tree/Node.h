#pragma once 

template <typename NodeType > class Tree;

template <typename NodeType >
class Node
{
	friend class Tree<NodeType>;
public:
	Node(const NodeType& nodeInfo);

	NodeType GetData() const;

private:
	NodeType m_Data;
	Node<NodeType>* m_LeftNodePtr;
	Node<NodeType>* m_RightNodePtr;
};

template<typename NodeType>
inline Node<NodeType>::Node(const NodeType& nodeInfo)
	: m_Data(nodeInfo)
	, m_LeftNodePtr(nullptr)
	, m_RightNodePtr(nullptr)
{
}

template<typename NodeType>
inline NodeType Node<NodeType>::GetData() const
{
	return m_Data;
}

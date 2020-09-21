#include "Graph.h"

AdjacencyInfo::AdjacencyInfo(GraphNode* node)
	: m_ParentNode(node)
	, m_ParentEdge(nullptr)
{}

AdjacencyInfo::AdjacencyInfo(GraphEdge* edge, int id)
	: m_Id(id)
	, m_ParentNode(nullptr)
	, m_ParentEdge(edge)
{}

int Graph::GetNumberOfNodes()
{
	return m_NodeList.size();
}

int Graph::GetNumberOfEdges()
{
	return m_EdgeList.size();
}

bool Graph::IsEmpty()
{
	return m_NodeList.empty();
}

Graph::Graph()
{

}

Graph::Graph(const Graph& graph)
{

}

Graph::~Graph()
{
	Clear();
}

GraphNode* Graph::CreateNode()
{
	GraphNode* newNode = new GraphNode();
	newNode->m_Id = m_NodeList.size();
	m_NodeList.push_back(newNode);

	return newNode;
}

GraphEdge* Graph::CreateEdge(GraphNode* startNode, GraphNode* endNode)
{
	AdjacencyInfo* adjStart = new AdjacencyInfo(endNode);
	startNode->m_AdjacenyList.push_back(adjStart);
	startNode->m_OutDegree++;

	AdjacencyInfo* adjEnd= new AdjacencyInfo(endNode);
	endNode->m_AdjacenyList.push_back(adjStart);
	endNode->m_InDegree++;

	adjStart->m_Twin = adjEnd;
	adjEnd->m_Twin = adjStart;

	GraphEdge* newEdge = CreateEdge(startNode, endNode, adjStart, adjEnd);
	adjStart->m_ParentEdge = adjEnd->m_ParentEdge = newEdge;
	return newEdge;
}

GraphEdge* Graph::CreateEdge(GraphNode* startNode, GraphNode* endNode, AdjacencyInfo* adjStart, AdjacencyInfo* adjEnd)
{
	int edgeId = m_EdgeList.size();
	GraphEdge* newEdge = new GraphEdge(startNode, endNode, adjStart, adjEnd, edgeId);
	m_EdgeList.push_back(newEdge);
	return newEdge;
}

GraphNode* Graph::GetFirstNode()
{
	if (m_NodeList.size() > 0)
		return m_NodeList[0];
	else return nullptr;

}

GraphNode* Graph::GetLastNode()
{
	if (m_NodeList.size() > 0)
		return m_NodeList[m_NodeList.size() - 1];
	else return nullptr;
}

GraphEdge* Graph::GetFirstEdge()
{
	if (m_EdgeList.size() > 0)
		return m_EdgeList[0];
	else return nullptr;
}

GraphEdge* Graph::GetLastEdge()
{
	if (m_EdgeList.size() > 0)
		return m_EdgeList[m_EdgeList.size() - 1];
	else return nullptr;
}

std::vector<GraphNode*>& Graph::GetAllNodes()
{
	return m_NodeList;
}

std::vector<GraphEdge*>& Graph::GetAllEdges()
{
	return m_EdgeList;
}

void Graph::Clear()
{
	for (size_t count = 0; count < m_NodeList.size(); count++)
	{
		if (m_NodeList[count])
		{
			delete m_NodeList[count];
		}
	}
	for (size_t count = 0; count < m_EdgeList.size(); count++)
	{
		if (m_EdgeList[count])
		{
			delete m_EdgeList[count];
		}
	}
	m_NodeList.clear();
	m_EdgeList.clear();
}

void Graph::ClearVisits()
{
	for (auto node : m_NodeList)
	{
		node->SetVisited(false);
	}
}

void Graph::RemoveNode(GraphNode* node)
{
	if (node)
	{
		auto it = std::find(m_NodeList.begin(), m_NodeList.end(), node);
		if (it != m_NodeList.end())
		{
			m_NodeList.erase(it);
			delete node;
			node = nullptr;
		}
	}
}

void Graph::RemoveEdge(GraphEdge* edge)
{
	if (edge)
	{
		auto it = std::find(m_EdgeList.begin(), m_EdgeList.end(), edge);
		if (it != m_EdgeList.end())
		{
			m_EdgeList.erase(it);
			delete edge;
			edge = nullptr;
		}	
	}
}

GraphEdge::GraphEdge(GraphNode* startNode, GraphNode* endNode, AdjacencyInfo* adjStart, AdjacencyInfo* adjEnd, int edgeId)
	: m_StartNode(startNode)
	, m_EndNode(endNode)
	, m_AdjStart(adjStart)
	, m_AdjEnd(adjEnd)
	, m_Id(edgeId)
{

}

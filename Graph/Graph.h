#pragma once

#include <vector>
#include <list>

class Graph;
class GraphNode;
class GraphEdge;
class AdjacencyInfo;

class GraphNode
{
	friend class Graph;
public:
	GraphNode()
	: m_Id(-1)
	, m_InDegree(0)
	, m_OutDegree(0)
	, m_Visited(false)
	{
	
	}
	void SetVisited(bool visited) { m_Visited = visited; }
	bool IsVisited() { return m_Visited; }
	int GetId() const { return m_Id; }
	int GetInDegree() const { return m_InDegree; }
	int GetOutDegree() const { return m_OutDegree; }
	std::list<AdjacencyInfo*>& GetAdjacencyList() { return m_AdjacenyList; }

private:
	int m_Id;
	int m_InDegree;
	int m_OutDegree;
	bool m_Visited;
	std::list<AdjacencyInfo*> m_AdjacenyList;
};

class GraphEdge
{
	friend class Graph;
public:
	GraphEdge(GraphNode* startNode, GraphNode* endNode, AdjacencyInfo* adjStart, AdjacencyInfo* adjEnd, int edgeId);
	int GetId() const { return m_Id; }
	GraphNode* GetStartNode() const { return m_StartNode; }
	GraphNode* GetEndNode() const { return m_EndNode; }
	AdjacencyInfo* GetAdjacencyInfoStart() const { return m_AdjStart; }
	AdjacencyInfo* GetAdjacencyInfoEnd() const { return m_AdjEnd; }
private:
	int m_Id;
	GraphNode* m_StartNode;
	GraphNode* m_EndNode;
	AdjacencyInfo* m_AdjStart;
	AdjacencyInfo* m_AdjEnd;
};

class AdjacencyInfo
{
	friend class Graph;
public:
	AdjacencyInfo(GraphNode* node);
	AdjacencyInfo(GraphEdge* edge, int id);
	int GetId() const { return m_Id; }
	AdjacencyInfo* GetTwin() { return m_Twin; }
	GraphNode* GetNode() { return m_ParentNode; }
	GraphEdge* GetEdge() { return m_ParentEdge; }
private:
	int m_Id;
	AdjacencyInfo* m_Twin;
	GraphNode* m_ParentNode;
	GraphEdge* m_ParentEdge;

};

class Graph
{
public:
	Graph();
	Graph(const Graph& graph);
	virtual ~Graph();

	GraphNode* CreateNode();
	GraphEdge* CreateEdge(GraphNode* startNode, GraphNode* endNode);
	GraphNode* GetFirstNode();
	GraphNode* GetLastNode();
	GraphEdge* GetFirstEdge();
	GraphEdge* GetLastEdge();

	std::vector<GraphNode*>& GetAllNodes();
	std::vector<GraphEdge*>& GetAllEdges();

	void Clear();
	void ClearVisits();
	void RemoveNode(GraphNode* node);
	void RemoveEdge(GraphEdge* edge);
	
	int GetNumberOfNodes();
	int GetNumberOfEdges();
	bool IsEmpty();

private:
	GraphEdge* CreateEdge(GraphNode* startNode, GraphNode* endNode, AdjacencyInfo* adjStart, AdjacencyInfo* adjEnd);
private:
	std::vector<GraphNode*> m_NodeList;
	std::vector<GraphEdge*> m_EdgeList;
};
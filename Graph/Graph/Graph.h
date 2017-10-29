#pragma once
#include <set>
#include <cassert>

template <class Type> class Graph
{
public:
	Graph();
	~Graph();
	void addVertex(const Type &value);
	void addEdge(int source, int target);
	void removeEdge(int source, int target);
	Type &operator[](int vertex);
	Type operator[](int vertex) const;
	int size();
	bool isEdge(int source, int target) const;
	std::set<int> neighbors(int vertex) const;
private:
	static const int maximum = 20;
	bool adjacencyMatrix[maximum][maximum];
	Type labels[maximum];
	int manyVertices;
};

template<class Type>
Graph<Type>::Graph()
{
}

template<class Type>
Graph<Type>::~Graph()
{
}

template<class Type>
const int Graph<Type>::maximum;

template<class Type>
void Graph<Type>::addVertex(const Type &value) 
{
	assert(size() < maximum);
	int newVertexNumber = manyVertices;
	manyVertices++;

	for (int otherVertexNumber = 0; otherVertexNumber < manyVertices; otherVertexNumber++)
	{
		adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
		adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
	}

	labels[newVertexNumber] = value;
}

template<class Type>
void Graph<Type>::addEdge(int source, int target)
{
	assert(source < size() && target < size());
	adjacencyMatrix[source][target] = true;

}

template<class Type>
bool Graph<Type>::isEdge(int source, int target) const
{
	assert(source < size() && target < size());
	bool isAnEdge = false;
	isAnEdge = adjecencyMatrix[source][target];
	return isAnEdge;
}

template <class Type>
void Graph<Type>::removeEdge(int source, int target)
{
	assert(source < size() && target < size());
	adjacencyMatrix[source][target] = false;
}

template<class Type>
std::set<int> Graph<Type>::neighbors(int vertex) const
{
	assert(vertex < size());
	std::set<int> vertexNeighbors;

	for (int index = 0; index < size(); index++)
	{
		if (adjacencyMatrix[vertex][index])
		{
			vertexNeighbors.insert(index);
		}
	}
	return vertexNeighbors;
}

template<class Type>
int Graph<Type>::size()
{
	return manyVertices;
}

template<class Type>
Type &Graph<Type>::operator[](int vertex)
{
	assert(vertex < size());
	return labels[vertex];
}

template<class Type>
Type Graph<Type>::operator[](int vertex) const
{
	assert(vertex < size());
	return labels[vertex];
}
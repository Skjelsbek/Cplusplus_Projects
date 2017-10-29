#include "Graph.h"

template <class Type>
const int Graph<Type>::maximum;

template <class Type>
Graph<Type>::Graph() {
}

template<class Type>
Graph<Type>::~Graph()
{
}

template<class Type>
void Graph<Type>::addVertex(const Type &value)
{
	assert(size() < maximum);
	int newVertexNumber = manyVertices;
	manyVertices++;
	
	for (int otherVertexNumber = 0; otherVertexNumber < manyVertices; otherVertexNumber++)
	{
		adjecencyMatrix[otherVertexNumber][newVertexNumber] = false;
		adjecencyMatrix[newVertexNumber][otherVertexNumber] = false;
	}

	labels[newVertexNumber] = value;
}

template<class Type>
void Graph<Type>::addEdge(int source, int target)
{
	assert(source < size() && target < size());
	adjecencyMatrix[source][target] = true;
}

template<class Type>
bool Graph<Type>::isEdge(int source, int target) const
{
	assert(source < size() && target < size());
	bool isAnEdge = false;
	isAnEdge = adjecencyMatrix[source][target];
	return isAnEdge;
}

template<class Type>
void Graph<Type>::removeEdge(int source, int target)
{
	assert(source < size() && target < size());
	adjecencyMatrix[source][target] = false;
}

template<class Type>
std::set<int> Graph<Type>::neighbors(int vertex) const
{
	assert(vertex < size());
	std::set<int> vertexNeighbors;

	for (int index = 0; index < size(); index++)
	{
		if (adjecencyMatrix[vertex][index])
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
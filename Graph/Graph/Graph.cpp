#include "Graph.h"

<<<<<<< HEAD
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
=======
int main()
{
	Graph<int> iGraph;
	Graph<char> cGraph;

	char cArr[] = { "abcdefghij" };
	int iArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 5; i++)
	{
		iGraph.addVertex(iArr[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		cGraph.addVertex(cArr[i]);
	}
>>>>>>> 929640bfff1666b07e49d581e2f27bf7d780c5ec
}
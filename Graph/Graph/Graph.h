#pragma once
#include <set>

template <class Type> class Graph{
private:
	static const int maximum = 20;
	bool adjecencyMatrix[maximum][maximum];
	Type labels[maximum];
	int manyVertices;
public:
	//Graph();
	//~Graph();

	void addVertex(const Type &value);
	void addEdge(int source, int target);
	bool isEdge(int source, int target) const;
	void removeEdge(int source, int target);
	std::set<int> neighbors(int vertex) const;
	int size();
	Type &operator[](int vertex);
	Type operator[](int vertex) const;
};

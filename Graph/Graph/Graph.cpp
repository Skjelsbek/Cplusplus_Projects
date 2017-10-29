#include "Graph.h"

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
}
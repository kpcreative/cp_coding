// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;
#include<map>
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// Function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	
	
    int edge;
    cin>>edge;
    while(edge--)
    {
        int src,dest;
        cin>>src>>dest;
       g.addEdge(src, dest);
    }

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	// Function call
	g.DFS(2);

	return 0;
}

//took by gfg
//main point is ki VISITED ARRAY WILL BE NA GLOBAALLY DECLARED OR PASSED BY REFRENCE
//AISA NHAI HOGA KI RETURN BACK HOTE WAQT YE UNVISITED MARK HO JIGA AISA NHI HAI
//YE PURA OVERALL VISTED MARTA HAI..DUBARA KOI US NODE PE JA HI NHI SKTA CHHAHE KUCH HO JAYE

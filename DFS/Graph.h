// using namespace std;
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

// data structure to store graph edges source and destination

class  Node
{
public:
	int value;
	bool visited;
	int previsited;
	int postvisited;
	Node(int value);
};

struct Edge {
	Node src, dest;
};

class Graph
{

    
public:
	std::vector<std::vector<Node>> adjList;
    int numVertices;
    //vector<int> adjLists;
    Graph(int V);
    void addEdge(Node src, Node dest);
    void explore(Node& v);
    void dfs();
    void showvisitState(std::string x);
};



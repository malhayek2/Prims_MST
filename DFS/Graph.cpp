#include "Graph.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


Node::Node(int value){
	this->value = value;
	this->visited = false;
	this->previsited = 0;
	this->postvisited = 0;
}
Graph::Graph(int vertices)
{
    this->numVertices = vertices;
    //adjLists = new list[vertices];
    this->adjList.resize(vertices);
}
 
void Graph::addEdge(Node src, Node dest)
{
    this->adjList[src.value].push_back(dest);
}
void Graph::explore(Node& v){
	//this->adjList[v.value].visited = true;
	// for (int i = 0; i < numVertices ; i++)
	// {
		//std::cout << "explore" <<std::endl;
		v.visited = true;
		v.previsited++;
		//std::cout << "check" << std::endl;
		if(this->adjList[v.value].size() != 0){
			//std::cout << "pre loop size of " << this->adjList[v.value].size() <<std::endl;
			//std::cout << "pre loop node of " << v.value << std::endl;
			for(int j = 0 ; j < this->adjList[v.value].size() && v.value != numVertices; j++){
			if(this->adjList[v.value].empty()){
				std::cout << "empty" << std::endl;
				continue;
			} 
			//std::cout << "j" << j << std::endl;	
			//std::cout << "accessing " << this->adjList[v.value].at(j).value << std::endl;
			this->adjList[v.value].at(j).visited = true;
			//std::cout << "next u" <<std::endl;
			explore(this->adjList[v.value].at(j));
			}			
		}

		v.postvisited++;

}

void  Graph::dfs(){
	// by default false

	for (int i = 0; i < numVertices  ; i++){
		for(int j = 0 ; j < this->adjList[i].size(); j++){
			//std::cout << "ex" << std::endl;
			explore(this->adjList[i][j]);
		}


	}

}

void Graph::showvisitState(std::string x){
	std::ofstream myfile;
	myfile.open (x + ".csv");
	for (int i = 0; i < numVertices  ; i++){
		for(int j = 0 ; j < this->adjList[i].size(); j++){
			//std::cout << "Node "  << this->adjList[i][j].value << " was previsited " << this->adjList[i][j].previsited << " was postvisited" << this->adjList[i][j].postvisited << std::endl;		
		    
      		
      		myfile  << this->adjList[i][j].value << "," << this->adjList[i][j].previsited << "," << this->adjList[i][j].postvisited << "," << "\n";		
			
		}
	}
	myfile.close();
}

void test(){

	Graph g(5);
    Node n0(0);
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);

    g.addEdge(n0, n1);
    g.addEdge(n1, n2);
    g.addEdge(n3, n4);
    g.addEdge(n0, n2);


	g.dfs();
	//g.explore(n0);
	for (int i = 0; i < 5; i++)
	{
		// print current vertex number
		std::cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (Node v : g.adjList[i])
			std::cout << v.value << "visited " << std::boolalpha <<  v.visited << " ";
		std::cout << std::endl;
	}
	//g.showvisitState();
	//std::cout << true << std::endl;
    
}
int main(int argc, char **argv)
{
std::string arg(argv[0]);
std::stringstream ss(arg);
std::string myText = argv[1]; 

std::cout << "open file "  << argv[1] << myText <<std::endl;
std::ifstream myfile;
myfile.open (myText);


// Use a while loop together with the getline() function to read the file line by line
// getline (myfile, myText); 
//   // Output the text from the file
//   std::cout << "size" << myText;
int size;
myfile >> size;
//std::cout << "size" << size << " " << std::endl;
Graph g(size);
int a, b,c;
while (myfile >> a >> b >> c)
{
	g.addEdge(Node(a), Node(b));

    //std::cout << a << " -> " << b << " weight " << c << " " <<std::endl;
}
// for (int i = 0; i < g.numVertices; i++)
// {
// 	// print current vertex number
// 	std::cout << i << " --> ";

// 	// print all neighboring vertices of vertex i
// 	for (Node v : g.adjList[i])
// 		std::cout << v.value << "visited " << std::boolalpha <<  v.visited << " ";
// 	std::cout << std::endl;
// }
std::cout << "DFS" << std::endl;
g.dfs();
std::cout << "Outputing file..." << std::endl;
g.showvisitState(myText);
// Close the file
myfile.close();

}
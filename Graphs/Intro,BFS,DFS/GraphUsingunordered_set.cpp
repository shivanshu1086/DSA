#include <iostream>
#include <unordered_set>
using namespace std;

class Graph{
public:
    int V;
    unordered_set<int> *adjList;
};

Graph *createGraph(int V){
    Graph *graph = new Graph;
    graph->V = V;
    graph->adjList = new unordered_set<int> [V];
    return graph;
}

void addEdge(Graph *graph, int src, int dest){
    graph->adjList[src].insert(dest);
    graph->adjList[dest].insert(src);
}

void printGraph(Graph *graph){
    for(int i=0;i<graph->V;i++){
        cout<<i<<" is connected to ";
        for(auto i:graph->adjList[i]){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void searchEdge(Graph *graph, int src, int dest){
    auto itr = graph->adjList[src].find(dest);
    if(itr==graph->adjList[src].end()){
        cout<<"No edge found between "<<src<<" and "<<dest<<endl;
    }
    else{
        cout<<"Edge found between "<<src<<" and "<<dest<<endl;
    }
}

int main() {
    int V=5;
    Graph *graph = createGraph(V);

    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4);

    printGraph(graph);

    searchEdge(graph, 2, 1); 
    searchEdge(graph, 0, 3);
    cout<<endl;
	return 0;
}
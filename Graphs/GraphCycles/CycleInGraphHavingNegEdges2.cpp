#include <iostream>

using namespace std;
class Edge{
public:
    int src,dest,weight;
};

class Graph{
public:
    int V,E;
    Edge *edge;
};

Graph *createGraph(int V, int E){
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

bool isNegCycleBellmanFord(Graph *graph, int src, int *dist){
    int V = graph->V; 
    int E = graph->E;

    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[src] = 0;

    for(int i=1;i<V;i++){
        for(int j=0;j<E;j++){
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight;
            if(dist[j]!=INT_MAX && dist[u]+weight<dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            return true; 
    }

    return false;
}

bool isNegCycleDisconnected(Graph *graph){
    int V = graph->V;
    int E = graph->E;

    bool visited[V];
    memset(visited,0,sizeof(visited));

    int dist[V];

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(isNegCycleBellmanFord(graph, i, dist)){
                return true;
            }
            for(int i=0;i<V;i++){
                if(dist[i]!=INT_MAX){
                    visited[i] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    int V = 5; // Number of vertices in graph 
    int E = 8; // Number of edges in graph 
    Graph* graph = createGraph(V, E); 
  
    // add edge 0-1 (or A-B in above figure) 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    if (isNegCycleDisconnected(graph)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    cout<<endl;
    return 0;
}
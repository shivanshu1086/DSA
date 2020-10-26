#include <iostream>

using namespace std;

class Edge{
public:
    int src;
    int dest;
    int weight;
};

class Graph{
public:
    int V,E;
    Edge *edge;
};

class subset{
public:
    int parent;
    int rank;
};

Graph *createGraph(int V, int E){
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int find(subset *subsets, int i){
    if(subsets[i].parent!=i){
        subsets[i].parent = find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset *subsets, int x, int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void boruvkaMST(Graph *graph){
    int V = graph->V, E = graph->E;
    Edge *edge = graph->edge;

    subset *subsets = new subset[V];

    int *cheapest = new int[V];

    for(int v=0;v<V;v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
        cheapest[v] = -1;
    }

    int numTrees = V;
    int MSTWeight = 0;

    while(numTrees>1){
        for(int v=0;v<V;v++){
            cheapest[v] = -1;
        }

        for(int i=0;i<E;i++){//get the cheapest edge
            int set1 = find(subsets, edge[i].src);
            int set2 = find(subsets, edge[i].dest);

            if(set1 == set2){
                continue;
            }

            else{
                if(cheapest[set1]==-1 || edge[cheapest[set1]].weight>edge[i].weight){
                    cheapest[set1] = i;
                }
                if(cheapest[set2]==-1 || edge[cheapest[set2]].weight>edge[i].weight){
                    cheapest[set2] = i;
                }
            }
        }


        //set the cheapest edge
        for(int i=0;i<V;i++){
            if(cheapest[i]!=-1){
                int set1 = find(subsets,edge[cheapest[i]].src);
                int set2 = find(subsets,edge[cheapest[i]].dest);

                if(set1==set2){
                    continue;
                }

                MSTWeight += edge[cheapest[i]].weight;

                printf("Edge %d-%d included in MST\n", 
                       edge[cheapest[i]].src, edge[cheapest[i]].dest);
                
                Union(subsets, set1, set2); 
                numTrees--;
            }
        }
    }

    printf("Weight of MST is %d\n", MSTWeight);
}

int main(){
    int V=4;
    int E=5;
    Graph* graph = createGraph(V, E);


    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = 10; 
  
    // add edge 0-2 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 6; 
  
    // add edge 0-3 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 3; 
    graph->edge[2].weight = 5; 
  
    // add edge 1-3 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 15; 
  
    // add edge 2-3 
    graph->edge[4].src = 2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    graph->edge[4].dest = 3; 
    graph->edge[4].weight = 4;

    boruvkaMST(graph);

    cout<<endl;
    return 0;
}
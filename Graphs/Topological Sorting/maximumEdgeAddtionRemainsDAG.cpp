#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    vector<int> indegree;
    vector<int> topologicalSort();
public:
    Graph(int V);
    void addEdge(int u, int v);
    void maximumEdgeAddtion();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    for(int i=0;i<V;i++){
        indegree.push_back(0);
    }
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    indegree[v]++;
}

vector<int> Graph::topologicalSort() 
{
    vector<int> topological; 
    queue<int> q;

    for (int i = 0; i < V; i++) 
        if (indegree[i] == 0) 
            q.push(i);

    while (!q.empty()) 
    { 
        int t = q.front(); 
        q.pop(); 
  
        //  push the node into topological vector 
        topological.push_back(t); 
  
        //  reducing indegree of adjacent vertices 
        for (list<int>:: iterator j = adj[t].begin(); 
                               j != adj[t].end(); j++) 
        { 
            indegree[*j]--; 
  
            //  if indegree becomes 0, just push 
            // into queue 
            if (indegree[*j] == 0) 
                q.push(*j); 
  
        } 
    } 
    return topological;
}

void Graph::maximumEdgeAddtion() 
{
    bool *visited = new bool[V]; 
    vector<int> topo = topologicalSort();

    for(int i=0;i<topo.size();i++){
        int t = topo[i];

        for (list<int>::iterator j = adj[t].begin(); 
                                 j != adj[t].end(); j++) 
            visited[*j] = true;

        for (int j = i + 1; j < topo.size(); j++) 
        { 
            // if not marked, then we can make an edge 
            // between t and j 
            if (!visited[topo[j]]) 
                cout << t << "->" << topo[j] << " "; 
  
            visited[topo[j]] = false; 
        }
    }
}

int main(){
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    g.maximumEdgeAddtion();
    cout<<endl;
    return 0;
}
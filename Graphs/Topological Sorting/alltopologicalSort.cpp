#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    vector<int> indegree;
    void alltopologicalSortUtil(vector<int> &res, bool visited[]);
public:
    Graph(int V);
    void addEdge(int u, int v);
    void alltopologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    this->adj = new list<int>[V];
    for (int i = 0; i < V; i++) 
        indegree.push_back(0);
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    indegree[v]++;
}

void Graph::alltopologicalSortUtil(vector<int> &res, bool *visited){
    bool flag = false;

    for(int i=0;i<V;i++){
        if(indegree[i]==0 && !visited[i]){
            for(auto itr=adj[i].begin();itr!=adj[i].end();itr++){
                indegree[*itr]--;
            }

            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, visited);//recursion for all

            visited[i] = false;//index reset for backtracking
            res.erase(res.end() - 1);
            for(auto itr=adj[i].begin();itr!=adj[i].end();itr++){
                indegree[*itr]++;
            }
            flag=true;
        }
    }

    if(!flag){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}

void Graph::alltopologicalSort(){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    vector<int> res;
    alltopologicalSortUtil(res,visited);
}

int main(){
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
    cout << "All Topological sorts\n"; 
  
    g.alltopologicalSort();
    cout<<endl;
    return 0;
}
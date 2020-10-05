#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    vector<int> indegree;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
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

void Graph::topologicalSort(){
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> top_order;
    int cnt=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        list<int>::iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++){
            if(--indegree[*itr]==0){
                q.push(*itr);
            }
        }
        cnt++;
    }
    if(cnt!=V){
        cout<<"cycle exists"<<endl;
    }
    for(auto i:top_order){
        cout<<i<<" ";
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
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort();
    cout<<endl;
    return 0;
}
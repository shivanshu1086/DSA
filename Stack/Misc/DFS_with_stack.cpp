#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
    void DFSUtil(int s, vector<bool> &visited);
};

Graph::Graph(int V){
    this->V=V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int s, vector<bool> &visited){
    stack<int> st;
    st.push(s);

    while(!st.empty()){
        s=st.top();
        st.pop();

        if(!visited[s]){
            cout<<s<<" ";
            visited[s]=true;
        }

        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                st.push(*i);
            }
        }
    }
}

void Graph::DFS(){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFSUtil(i,visited);
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(1,4);

    g.DFS();
    cout<<endl;
	return 0; 
}
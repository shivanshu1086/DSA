#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
//path searching from both direction
//min. time BFS
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    int biDirSearch(int s, int d);
    void BFS(list<int> adj[], bool visited[], int parent[]);
    int isIntersecting(bool s_visited[], bool t_visited[]);
    void printPath(int s_parent[], int t_parent[], int s, int d, int intersectingP);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS(list<int> *queue, bool *visited, int *parent){
    int current = queue->front();

    queue->pop_front();

    list<int>::iterator i;
    for(i=adj[current].begin();i!=adj[current].end();i++){
        if(!visited[*i]){
            parent[*i] = current;
            visited[*i] = true;
            queue->push_back(*i);
        }
    }
}

int Graph::isIntersecting(bool *s_visited, bool *t_visited){
    int intersectNode = -1;
    for(int i=0;i<V;i++){
        if(s_visited[i] && t_visited[i]) 
            return i;
    }
    return -1;
}

void Graph::printPath(int *s_parent, int *t_parent, int s, int d, int intersectingP){
    vector<int> path;

    path.push_back(intersectingP);

    int i = intersectingP;

    while(i!=s){
        path.push_back(s_parent[i]);
        i = s_parent[i];
    }

    reverse(path.begin(),path.end());
    i = intersectingP;

    while(i!=d){
        path.push_back(t_parent[i]);
        i=t_parent[i];
    }
    cout<<"*****Path*****\n";
    for(auto i:path){
        cout<<i<<" ";
    }
    cout<<endl;
}

int Graph::biDirSearch(int s, int t){
    bool s_visited[V], t_visited[V];
    memset(s_visited,false,sizeof(s_visited));
    memset(t_visited,false,sizeof(t_visited));
    int s_parent[V], t_parent[V];

    list<int> s_queue, t_queue;//*queue for front and backward search

    int intersectNode = -1;

    s_queue.push_back(s);
    s_visited[s] = true;
    s_parent[s] = -1;
    t_queue.push_back(t);
    t_visited[t] = true;
    t_parent[t] = -1;

    while(!s_queue.empty() && !t_queue.empty()){
        BFS(&s_queue, s_visited, s_parent); 
        BFS(&t_queue, t_visited, t_parent);


        intersectNode = isIntersecting(s_visited, t_visited);

        if(intersectNode!=-1){
            cout << "Path exist between " << s << " and "
                 << t << "\n"; 
            cout << "Intersection at: " << intersectNode << "\n";
            printPath(s_parent, t_parent, s, t, intersectNode);
            return 1;
        }
    }
    return -1;
}


int main(){
    int n=15;
    Graph g(n);

    int s=0,d=14;

    g.addEdge(0, 4); 
    g.addEdge(1, 4); 
    g.addEdge(2, 5); 
    g.addEdge(3, 5); 
    g.addEdge(4, 6); 
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 
    g.addEdge(7, 8); 
    g.addEdge(8, 9); 
    g.addEdge(8, 10); 
    g.addEdge(9, 11); 
    g.addEdge(9, 12); 
    g.addEdge(10, 13); 
    g.addEdge(10, 14);

    if (g.biDirSearch(s, d) == -1) 
        cout << "Path don't exist between "
             << s << " and " << d << "\n";
    cout<<endl;
	return 0;
}
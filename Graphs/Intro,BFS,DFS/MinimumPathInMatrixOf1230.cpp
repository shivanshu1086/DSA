#include <iostream>
#include <vector>
#include <list>
#define N 4
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    int BFS ( int s , int d);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool is_safe(int i,int j, int m[][N]){
    if((i<0 || i>=N) || (j<0 || j>=N) || (m[i][j]==0)){
        return false;
    }
    return true;
}

int Graph::BFS(int s, int d){
    if(s==d){
        return 0;
    }

    int *level = new int[V];
    for(int i=0;i<V;i++){
        level[i] = -1;
    }

    list<int> queue;

    level[s] = 0;
    queue.push_back(s);

    // list<int>::iterator i;
    while(!queue.empty()){
        s = queue.front(); 
        queue.pop_front();

        for(auto i = adj[s].begin();i!=adj[s].end();i++){
            if(level[*i]<0 || level[*i]>level[s]+1){
                level[*i] = level[s] + 1 ;
                queue.push_back(*i);
            }
        }
    }
    return level[d];
}

int MinimumPath(int m[N][N]){
    int s , d ; // source and destination 
    int V = N*N+2; 
    Graph g(V);

    int k=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(m[i][j]!=0){
                if(is_safe(i,j+1,m)){
                    g.addEdge(k,k+1);
                }
                if(is_safe(i,j-1,m)){
                    g.addEdge(k,k-1);
                }
                if(j<N-1 && is_safe(i+1,j,m)){
                    g.addEdge(k,k+N);
                }
                if(i>0 && is_safe(i-1,j,m)){
                    g.addEdge(k,k-N);
                }
            }

            if(m[i][j]==1){
                s=k;
            }

            if(m[i][j]==2){
                d=k;
            }

            k++;
        }
    }
    return g.BFS(s,d);
}

int main(){
    int M[N][N] = {{ 3 , 3 , 1 , 0 }, 
        { 3 , 0 , 3 , 3 }, 
        { 2 , 3 , 0 , 3 }, 
        { 0 , 3 , 3 , 3 } 
    }; 
  
    cout << MinimumPath(M) << endl;
    
    cout<<endl;
    return 0;
}
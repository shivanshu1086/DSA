#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100001;
bool visit[MAX] = {0};

// To store start and end time of all vertices 
// during DFS. 
int intime[MAX]; 
int outtime[MAX];

// initially timer is zero 
int timer = 0; 

void dfs(vector<int> graph[], int v) 
{
    visit[v] = true;

    ++timer;

    intime[v] = timer;

    for(auto i:graph[v]){
        if(!visit[i]){
            dfs(graph,i);
        }
    }

    ++timer;

    outtime[v] = timer;
}

bool query(int u, int v) 
{
    return ((intime[u]<intime[v] && outtime[u]>outtime[v]) || 
            (intime[u]>intime[v] && outtime[u]<outtime[v]));
}

int main(){
    int n = 9; // total number of nodes 
    vector<int> graph[n+1]; 
    graph[1].push_back(2); 
    graph[1].push_back(3); 
    graph[3].push_back(6); 
    graph[2].push_back(4); 
    graph[2].push_back(5); 
    graph[5].push_back(7); 
    graph[5].push_back(8); 
    graph[5].push_back(9); 
  
    // Start dfs (here root node is 1) 
    dfs(graph, 1); 
  
    // below are calls for few pairs of nodes 
    query(1, 5)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 9)? cout << "Yes\n" : cout << "No\n"; 
    query(2, 6)? cout << "Yes\n" : cout << "No\n";
    cout<<endl;
    return 0;
}
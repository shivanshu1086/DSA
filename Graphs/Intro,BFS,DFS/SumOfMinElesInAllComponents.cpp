#include <iostream>
#include <vector>


using namespace std;
const int N = 10000; 

vector<int> graph[N];

bool visited[N]; 

void addedge(int u, int v) 
{ 
    graph[u - 1].push_back(v - 1); 
    graph[v - 1].push_back(u - 1); 
}

void dfs(int node, int *a, int &mini){
    mini = min(mini, a[node]);

    visited[node] = true;

    for(int i:graph[node]){
        if(!visited[i]){
            dfs(i, a, mini);
        }
    }
}

int minimumSumConnectedComponents(int a[], int n) 
{
    int sum=0;
    
    for(int i=0;i<n;i++){
        if (!visited[i]){
            int mini = a[i];
            dfs(i, a, mini);
            sum += mini;
        }
    }

    return sum;
}

int main(){
    int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10}; 
      
    // Add edges 
    addedge(1, 2); 
    addedge(3, 4); 
    addedge(5, 6); 
    addedge(7, 8); 
    addedge(9, 10); 
      
    int n = sizeof(a) / sizeof(a[0]);
    cout << minimumSumConnectedComponents(a, n);
    cout<<endl;
    return 0;
}
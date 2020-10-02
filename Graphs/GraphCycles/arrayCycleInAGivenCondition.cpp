#include <iostream>
#include <vector>

using namespace std;

bool is_cyclic(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &recur){
    visited[src] = true;
    recur[src] = true;

    for(int i=0;i<adj[src].size();i++){
        if(!visited[adj[src][i]] && is_cyclic(adj[src][i],adj,visited,recur)){
            return true;
        }
        else if(recur[adj[src][i]] && visited[adj[src][i]]){
            return true;
        }
    }
    recur[src] = false;
    return false;
}

bool isCycle(int *arr, int n){
    vector<int>adj[n];

    for(int i=0;i<n;i++){
        if(i!=(i+arr[i]+n)%n){
            adj[i].push_back((i+arr[i]+n)%n);
        }
    }

    vector<bool>visited(n,false);
    vector<bool> recur(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(is_cyclic(i,adj,visited,recur)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {2, -1, 1, 2, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    if (isCycle(arr, n)) 
        cout << "Yes"<<endl; 
    else
        cout << "No"<<endl;
    cout<<endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> list[], int node, int arrival) 
{
    cout << node << '\n';
    for (int i = 0; i < list[node].size(); i++) { 
  
        // Not traversing the parent node 
        if (list[node][i] != arrival) 
            dfs(list, list[node][i], node); 
    }
}

int main(){
    int nodes = 5; 
  
    // Adjacency list 
    vector<int> list[10000]; 
  
    // Designing the tree 
    list[1].push_back(2); 
    list[2].push_back(1); 
  
    list[1].push_back(3); 
    list[3].push_back(1); 
  
    list[2].push_back(4); 
    list[4].push_back(2); 
  
    list[3].push_back(5); 
    list[5].push_back(3);

    dfs(list, 1, 0);
    cout<<endl;
	return 0;
}
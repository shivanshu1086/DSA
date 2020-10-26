#include <iostream>
#include <vector>

using namespace std;

int minNode(int n, int *keyVal, bool *mySet){
    int min = INT_MAX, min_index;
    for(int i=0;i<n;i++){
        if(!mySet[i] && keyVal[i]<min){
            min = keyVal[i];
            min_index = i;
        }
    }
    return min_index;
}

void findcost(int n, vector<vector<int> > city){
    int parent[n];
    int keyVal[n];

    bool mySet[n];

    for(int i=0;i<n;i++){
        keyVal[i] = INT_MAX;
        mySet[i]=false;
    }

    parent[0] = -1;
    keyVal[0] = 0;

    for(int i=0;i<n-1;i++){
        int u = minNode(n,keyVal,mySet);
        mySet[u] = true;

        for(int v=0;v<n;v++){
            if(city[u][v] && !mySet[v] && city[u][v]<keyVal[v]){
                keyVal[v] = city[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0; 
    for (int i = 1; i < n; i++) 
        cost += city[parent[i]][i]; 
    cout << cost << endl;
}


int main(){
    int n1 = 5; 
    vector<vector<int>> city1 = {{0, 1, 2, 3, 4}, 
                                {1, 0, 5, 0, 7}, 
                                {2, 5, 0, 6, 0}, 
                                {3, 0, 6, 0, 0}, 
                                {4, 7, 0, 0, 0}}; 
    findcost(n1, city1); 
    
    // Input 2 
    int n2 = 6; 
    vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0}, 
                                {1, 0, 1, 0, 0, 0}, 
                                {1, 1, 0, 0, 0, 0},    
                                {100, 0, 0, 0, 2, 2}, 
                                {0, 0, 0, 2, 0, 2},   
                                {0, 0, 0, 2, 2, 0}}; 
    findcost(n2, city2);

    cout<<endl;
    return 0;
}
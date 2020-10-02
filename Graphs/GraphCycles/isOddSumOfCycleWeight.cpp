#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool twoColorUtil(vector<int> G[], int src, int N, int *colorArr){
    colorArr[src]=1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0;i<G[u].size();i++){
            if(colorArr[G[u][i]]==-1){
                colorArr[G[u][i]] = 1 - colorArr[u];
                q.push(G[u][i]);
            }
            else if(colorArr[G[u][i]]==colorArr[u]){
                return false;
            }
        }
    }
    return true;
}

bool twoColor(vector<int> G[], int N){
    int colorArr[N]; 
    for (int i = 1; i <= N; ++i) 
        colorArr[i] = -1;

    for(int i=1;i<=N;i++){
        if(colorArr[i]==-1){
            if(twoColorUtil(G,i,N,colorArr)==false){
                return false;
            }
        }
    }
    return true;
}

bool isOddSum(int info[][3], int n, int m){
    vector<int> G[2*n];

    int pseduo = n+1;
    int pseudo_count = 0;

    for(int i=0;i<m;i++){//graph creation
        if(info[i][2]%2==1){//odd edge
            int u = info[i][0];
            int v = info[i][1];

            G[u].push_back(v);
            G[v].push_back(u);
        }

        else{//even edge
            int u = info[i][0];
            int v = info[i][1];

            G[u].push_back(pseduo);
            G[pseduo].push_back(u);
            G[v].push_back(pseduo);
            G[pseduo].push_back(v);

            pseudo_count++;

            pseduo++;
        }
    }

    return twoColor(G,n+pseudo_count);
}

int main(){
    int n = 4, m = 3; 
    int info[4][3] = {{1, 2, 12}, 
                     {2, 3, 1}, 
                     {4, 3, 1}, 
                     {4, 1, 20}};

    if (isOddSum(info, n, m) == true) 
        cout << "No\n"; 
    else
        cout << "Yes\n";
    cout<<endl;
    return 0;
}
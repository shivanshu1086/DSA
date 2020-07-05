#include <iostream>
#include <queue>
#define N 3
#define M 4
using namespace std;

void printdistance(int a[N][M]){
    int ans[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int l=0;l<N;l++){
                for(int k=0;k<M;k++){
                    if(a[l][k]==1){
                        ans[i][j]=min(ans[i][j],(abs(i-l)+abs(j-k)));
                    }
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int mat[N][M]={
        0,0,0,1,
        0,0,1,1,
        0,1,1,0
    };
    printdistance(mat);
    cout<<endl;
	return 0;
}
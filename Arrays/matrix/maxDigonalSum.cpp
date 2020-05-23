#include <iostream>
#include <unordered_map>
#include <map>
#define N 4 
#define M 6
// #define N 100
using namespace std;

void maxDigonalSum(int a[][M]){
    for(int i=1;i<N;i++){//2-D DP way
        for(int j=0;j<M;j++){
            if(j>0 && j<M-1){
                a[i][j]+=max(a[i - 1][j],max(a[i - 1][j - 1], a[i - 1][j + 1]));
            }

            else if(j>0){
                a[i][j]+=max(a[i - 1][j], a[i - 1][j - 1]); 
            }

            else if(j<M-1){
                a[i][j]+=max(a[i - 1][j],a[i - 1][j + 1]);
            }
        }
    }//result has been stored in the last row of dp array

    int res=0;
    for(int i=0;i<M;i++){
        res=max(res,a[N-1][i]);
    }
    cout<<res;
}


int main()
{
    int a[][M] = {   { 10, 10, 2, 0, 20, 4 },
                    { 1, 0, 0, 30, 2, 5 }, 
                    { 0, 10, 4, 0, 2, 0 }, 
                    { 1, 0, 2, 20, 0, 4 } };
    maxDigonalSum(a);
	cout<<endl;
    return 0;
}

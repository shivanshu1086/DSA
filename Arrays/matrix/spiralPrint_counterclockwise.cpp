#include <iostream>
#include <unordered_map>
#include <map>

#define N 100
using namespace std;

void spiralPrint_counterclockwise(int a[][N], int i, int j, int r, int c){
    if(i>=r or j>=c){
        return;
    }

    for(int p=i;p<r;p++){
        cout<<a[p][i]<<" ";
    }//first column

    for(int p=i+1;p<c;p++){
        cout<<a[r-1][p]<<" ";
    }//last row

    if((c-1)!=j){
        for(int p=r-2;p>=i;p--){
            cout<<a[p][c-1]<<" ";
        }
    }//last column

    if((r-1)!=i){
        for(int p=c-2;p>j;p--){
            cout<<a[i][p]<<" ";
        }
    }//first row
    spiralPrint_counterclockwise(a,i+1,j+1,r-1,c-1);
}

int main()
{
    int a[][N] = {{ 1, 2, 3, 20},
                     {5, 6, 20, 25}, 
                     {1, 3, 5, 6}, 
                     {6, 7, 8, 15}};

    spiralPrint_counterclockwise(a,0,0,4,4);
	cout<<endl;
    return 0;
}

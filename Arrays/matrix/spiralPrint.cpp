#include <iostream>
#include <unordered_map>

#define MAX 100
using namespace std;

void spiralPrint(int a[][MAX], int i, int j, int r, int c){
    if(i>=r or j>=c){
        return;
    }//base condition

    for(int p=i;p<c;p++){
        cout<<a[i][p]<<" ";
    }//first row

    for(int p=i+1;p<r;p++){
        cout<<a[p][c-1]<<" ";
    }//last column

    //if first and last row are not same
    if((r-1)!=i){
        for(int p=c-2;p>=j;p--){
            cout<<a[r-1][p]<<" ";
        }
    }//last row

    //if last and first column are not same
    if((c-1)!=j){
        for(int p=r-2;p>i;p--){
            cout<<a[p][j]<<" ";
        }
    }//first column

    //further spiral
    spiralPrint(a,i+1,j+1,r-1,c-1);
}

int main()
{
    int a[][MAX]={{1,2,3,4},
                  {5,6,7,8},
                  {9,10,11,12},
                  {13,14,15,16}};
    int r=4,c=4;
    spiralPrint(a,0,0,r,c);
	cout<<endl;
    return 0;
}

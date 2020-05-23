#include <iostream>
#include <unordered_map>
#include <map>

#define N 100
using namespace std;

void swap_major_minor_digonal(int a[][N], int r, int c){
    for(int i=0;i<c;i++){
        swap(a[i][i],a[i][c-i-1]);
    }

    //print
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a[][N] = {  { 1, 2, 3, 20},
                     {5, 6, 20, 25}, 
                     {1, 3, 5, 6}, 
                     {6, 7, 8, 15}};
    int r=4;
    int c=4;
    swap_major_minor_digonal(a,r,c);
	cout<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>
#define n 4
#define r 4
#define c 4
using namespace std;



//Transpose way
void anticlockwise_rotation(int a[r][c]){
    //transpose
    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            swap(a[i][j],a[j][i]);
        }
    }

    //reverse the columns
    for(int i=0;i<c;i++){
        for(int j=0,k=r-1;j<k;j++,k--){
            swap(a[j][i],a[k][i]);
        }
    }

    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            swap(a[i][j],a[j][i]);
        }
    }

    for(int i=0;i<c;i++){
        for(int j=0,k=r-1;j<k;j++,k--){
            swap(a[j][i],a[k][i]);
        }
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
    int a[r][c] = { {1,  2,  3,  4}, 
                    {5,  6,  7,  8}, 
                    {9,  10, 11, 12}, 
                    {13, 14, 15, 16}  } ;
    //we can print in that manner directly
// { 
//     // Simply print from last cell to first cell. 
//     for (int i = N - 1; i >= 0; i--) { 
//         for (int j = N - 1; j >= 0; j--) 
//             printf("%d ", mat[i][j]); 
  
//         printf("\n"); 
//     } 
// } or
    anticlockwise_rotation(a);
	cout<<endl;
    return 0;
}

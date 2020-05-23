#include <iostream>
#include <climits>

#define N 3
using namespace std;

void scalarProductMat(int a[N][N], int k){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]*=k;
        }
    }
}

int main()
{
    int mat[N][N] = { { 1, 2, 3 }, 
                      { 4, 5, 6 }, 
                      { 7, 8, 9 } }; 
    int k = 4; 
  
    scalarProductMat(mat, k); 
  
    // to display the resultant matrix 
    printf("Scalar Product Matrix is : \n"); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++)  
            printf("%d ", mat[i][j]); 
        printf("\n"); 
    }
	cout<<endl;
    return 0;
}

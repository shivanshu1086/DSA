#include <iostream>
#include <climits>

#define MAX 100
using namespace std;

void multiplyMatrix(int a[][MAX], int row1, int col1, int b[][MAX], int row2, int col2, int c[][MAX]){
    static int i=0,j=0,k=0;
    if(i>=row1){
        return;
    }//if all rows are traversed of 'a' matrix then return

    if(j<col2){
        if(k<col1){
            c[i][j]+=a[i][k]*b[k][j];
            k++;
            multiplyMatrix(a,row1,col1,b,row2,col2,c);
        }
        k=0;
        j++;
        multiplyMatrix(a,row1,col1,b,row2,col2,c);
    }
    j=0;
    i++;
    multiplyMatrix(a,row1,col1,b,row2,col2,c);
}

void matrixMultiplyRecursive(int a[][MAX], int row1, int col1, int b[][MAX], int row2, int col2){
    if(col1!=row2){
        cout<<"Multiplication Not possible!";
        return;
    }
    int c[MAX][MAX]={0};
    multiplyMatrix(a,row1,col1,b,row2,col2,c);
    
    //print the matrix
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int A[][MAX] = { {1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9}}; 
  
    int B[][MAX] = { {1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9} }; 
  
    int row1 = 3, col1 = 3, row2 = 3, col2 = 3;
    matrixMultiplyRecursive(A,row1,col1,B,row2,col2);
	cout<<endl;
    return 0;
}

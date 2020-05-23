#include <iostream>
#include <climits>

#define N 3
using namespace std;

void lowerTriangle(int a[3][3], int row, int col){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i<j){
                cout<<"0"<<" ";
            }
            else
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void UpperTriangle(int a[3][3], int row, int col){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i>j){
                cout<<"0"<<" ";
            }
            else
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a[3][3] = {{1, 2, 3},  
                        {4, 5, 6},  
                        {7, 8, 9}}; 
    int row = 3, col = 3;
    lowerTriangle(a,row,col);
    cout<<endl;
    UpperTriangle(a,row,col);
	cout<<endl;
    return 0;
}

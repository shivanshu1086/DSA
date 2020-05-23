#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>

#define SIZE 1000
using namespace std;

void sortthematrix(int a[SIZE][SIZE], int n){
    int temp[n*n];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[k++]=a[i][j];
        }
    }
    sort(temp,temp+k);
    k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=temp[k++];
        }
    }

    //print the array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a[SIZE][SIZE] = {{ 5, 4, 7 }, 
                        { 1, 3, 8 }, 
                        { 2, 9, 6 } }; 
    int n = 3;
    sortthematrix(a,n);
	cout<<endl;
    return 0;
}

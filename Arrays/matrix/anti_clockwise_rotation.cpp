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

void anti_clockwise_rotation(int a[r][c]){
    int row=0,col=0;
    int prev_ele,curr_ele;
    for(int i=0;i<n/2;i++){//by swapping the no of sqaures//i.e first with last and so on.
        for(int j=i;j<n-i-1;j++){
            int curr_ele=a[i][j];
            a[i][j]=a[j][n-1-i];
            a[j][n-1-i]=a[n-1-i][n-1-j];
            a[n-1-i][n-1-j]=a[n-1-j][i];
            a[n-1-j][i]=curr_ele;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

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
    // anti_clockwise_rotation(a);
    anticlockwise_rotation(a);
	cout<<endl;
    return 0;
}

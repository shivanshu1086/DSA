#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>

#define r 4
#define c 4
using namespace std;

void clockwise_rotation(int a[r][c], int m, int n){
        int row=0,col=0;
        int prev_ele,curr_ele;
        while(row<m && col<n){
            if(row+1==m || col+1==n){
                break;
            }//if all the elements have done
            prev_ele=a[row][col+1];
            
            for(int i=row;i<m;i++){
                curr_ele=a[i][col];
                a[i][col]=prev_ele;
                prev_ele=curr_ele;
            }
            col++;
            
            for(int i=col;i<n;i++){
                curr_ele=a[n-1][i];
                a[n-1][i]=prev_ele;
                prev_ele=curr_ele;
            }
            m--;

            if(col<n){
                
                for(int i=m-1;i>=row;i--){
                    curr_ele=a[i][n-1];
                    a[i][n-1]=prev_ele;
                    prev_ele=curr_ele;
                }
            }
            n--;
            if(row<m){
                
                for(int i=n-1;i>=col;i--){
                    curr_ele=a[row][i];
                    a[row][i]=prev_ele;
                    prev_ele=curr_ele;
                }
            }
            row++;
        }
}

int main()
{
    int a[r][c] = { {1,  2,  3,  4}, 
                    {5,  6,  7,  8}, 
                    {9,  10, 11, 12}, 
                    {13, 14, 15, 16}  };
    int k=3;
    while(k--)clockwise_rotation(a,r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
	cout<<endl;
    return 0;
}

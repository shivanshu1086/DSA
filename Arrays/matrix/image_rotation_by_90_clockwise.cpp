#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>

#define r 4
#define c 4
using namespace std;

void image_rotation_by_90_clockwise(int a[r][c], int row, int col){
    int b[c][r];//as transpose reverse the count of rows and columns
    
    //transpose
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            // swap(a[i][j],a[j][i]);//if using without space
            b[j][i]=a[i][j];
        }
    }

    //swaping
    for(int i=0;i<(row/2);i++){
        int k=i;
        for(int j=0;j<col;j++){
            swap(b[j][k],b[j][row-1-k]);
        }
    }

    //printing
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int a[r][c] = { {1,5,9,13},
                    {2,6,10,14},
                    {3,7,11,15},
                    {4,8,12,16} } ;
    // vector<vector<int> > a(c, vector<int> (r)); //created a 2d vector with c rows and r columns for aination matrix
    image_rotation_by_90_clockwise(a,r,c);
	cout<<endl;
    return 0;
}

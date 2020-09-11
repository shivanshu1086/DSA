#include <iostream>
#include <unordered_map>
const int MAX = 100;
using namespace std;

void pairSum(int mat[][MAX], int n, int sum) 
{
    unordered_map<int, pair<int, int> > hm;
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            hm[mat[i][j]] = make_pair(i, j);
    
    for (int i=0; i<n; i++) 
    { 
        for (int j=0; j<n; j++) 
        {
            int remSum = sum - mat[i][j];
            auto it = hm.find(remSum); 
            if (it != hm.end()) 
            {
                int row = it->second.first;
                int col = it->second.second;
                if (row != i && row > i) 
                   cout << "(" << mat[i][j] << ", "
                        << mat[row][col] << "), ";
            }
        }
    }
}

int main(){
    int n = 4, sum = 11; 
    int mat[][MAX]= {{1, 3, 2, 4}, 
                     {5, 8, 7, 6}, 
                     {9, 10, 13, 11}, 
                     {12, 0, 14, 15}}; 
    pairSum(mat, n, sum); 
    cout<<endl;
    return 0;
}
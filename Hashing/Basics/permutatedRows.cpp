#include <iostream>
#include <unordered_set>
#define MAX 100
using namespace std;

void permutatedRows(int mat[][MAX], int m, int n, int r) 
{
    unordered_set<int> s;
    for (int j=0; j<n; j++) 
        s.insert(mat[r][j]);
    
    for (int i=0; i<m; i++) 
    {
        if(i==r){
            continue;
        }

        int j;
        for (j=0; j<n; j++) 
            if (s.find(mat[i][j]) == s.end()) 
                break;
        if (j != n) 
           continue;
        cout << i << ", ";
    }
}

int main(){
    int m = 4, n = 4,r = 3; 
    int mat[][MAX] = {{3, 1, 4, 2}, 
                      {1, 6, 9, 3}, 
                      {1, 2, 3, 4}, 
                      {4, 3, 2, 1}}; 
    permutatedRows(mat, m, n, r);
    cout<<endl;
    return 0;
}
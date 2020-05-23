#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>

#define MAX 1000
using namespace std;

bool isPermutedMatrix(int a[MAX][MAX], int n){
    string str_cat="";
    for(int i=0;i<n;i++){
        str_cat=str_cat+"-"+to_string(a[0][i]);
    }
    str_cat+=str_cat;
    for(int i=1;i<n;i++){
        string cur_str="";
        for(int j=0;j<n;j++){
            cur_str=cur_str+"-"+to_string(a[i][j]);
        }
        if(str_cat.find(cur_str) == string::npos){//this is a comparison with -1
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 4 ; 
    int mat[MAX][MAX] = {{1, 2, 3, 4}, 
                        {4, 1, 2, 3}, 
                        {3, 4, 1, 2}, 
                        {2, 3, 4, 1}}; 
    isPermutedMatrix(mat, n)? cout << "Yes" : 
                              cout << "No";
    
	cout<<endl;
    return 0;
}

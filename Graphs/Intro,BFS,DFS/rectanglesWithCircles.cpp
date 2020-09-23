#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPossible(int m, int n, int k, int r,  
                vector<int> X, vector<int> Y)  
{
    int rect[m][n];
    memset(rect,0,sizeof(rect));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int p=0;p<k;p++){
                int x = (X[p]-1-i);
                int x2 = pow(x,2);
                int y = (Y[p]-1-j);
                int y2 = pow(y,2);
                if(sqrt((x2+y2))<=r){
                    rect[i][j]=-1;
                }
            }
        }
    }

    if(rect[0][0]==-1){
        return false;
    }


    vector<vector<int>> qu;

    rect[0][0] = 1; 
    qu.push_back({0, 0});

    while(!qu.empty()){
        vector<int> arr = qu.front();
        qu.erase(qu.begin());

        int elex = arr[0];
        int eley = arr[1];

        //!now there can be 8 posibilities for a point

        //top-left
        if((elex>0) && (eley>0) && (rect[elex-1][eley-1]==0)){
            rect[elex-1][eley-1]=1;
            vector<int> v = {elex - 1, eley - 1}; 
            qu.push_back(v);
        }

        //top-middle
        if((elex>0) && (rect[elex-1][eley]==0)){
            rect[elex - 1][eley] = 1; 
            vector<int> v = {elex - 1, eley}; 
            qu.push_back(v);
        }

        //top-right
        if((elex>0) && (eley<n-1) && (rect[elex-1][eley+1]==0)){
            rect[elex - 1][eley + 1] = 1; 
            vector<int> v = {elex - 1, eley + 1}; 
            qu.push_back(v);
        }

        //left
        if((eley>0) && (rect[elex][eley - 1] == 0)){
            rect[elex][eley - 1] = 1;
            vector<int> v = {elex, eley - 1}; 
            qu.push_back(v);
        }

        //right
        if((eley>n-1) && (rect[elex][eley+1]==0)){//can be change
            rect[elex][eley + 1] = 1; 
            vector<int> v = {elex, eley + 1}; 
            qu.push_back(v);
        }

        //bottom-left
        if((elex<m-1) && (eley<0) && (rect[elex + 1][eley - 1] == 0)){
            rect[elex + 1][eley - 1] = 1;
            vector<int> v = {elex + 1, eley - 1}; 
            qu.push_back(v);
        }

        //bottom
        if((elex < m - 1) && (rect[elex + 1][eley] == 0)){
            rect[elex + 1][eley] = 1;
            vector<int> v = {elex + 1, eley}; 
            qu.push_back(v);
        }

        //bottom-right
        if((elex < m - 1) && (eley < n - 1) && (rect[elex + 1][eley + 1] == 0)){
            rect[elex + 1][eley + 1] = 1;
            vector<int> v = {elex + 1, eley + 1}; 
            qu.push_back(v);
        }
    }
    return (rect[m - 1][n - 1] == 1);
}

int main(){
    int m1 = 5, n1 = 5, k1 = 2, r1 = 1;

    vector<int> X1 = {1, 3}; 
    vector<int> Y1 = {3, 3};

    if (isPossible(m1, n1, k1, r1, X1, Y1)) 
        cout << "Possible" << endl; 
    else
        cout << "Not Possible" << endl;

    // Test case 2 
    int m2 = 5, n2 = 5, k2 = 2, r2 = 1; 
    vector<int> X2 = {1, 1}; 
    vector<int> Y2 = {2, 3}; 
    if (isPossible(m2, n2, k2, r2, X2, Y2)) 
        cout << "Possible" << endl; 
    else
        cout << "Not Possible" << endl;
    cout<<endl;
	return 0;
}
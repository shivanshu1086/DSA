#include <iostream>
#include <unordered_map>
#include <map>

#define N 100
using namespace std;

void unique_elements(int a[][N], int r, int c){
    unordered_map<int,int> m;
    int i=0;
    while(i<r){
        for(int j=0;j<c;j++){
            m[a[i][j]]++;
        }
        i++;
    }

    for(auto i:m){
        if(i.second==1){
            cout<<i.first<<" ";
        }
    }
    // cout<<endl<<endl;

    //testing
    /*map<int,int> mp;
    i=0;
    while(i<r){
        for(int j=0;j<c;j++){
            mp[a[i][j]]++;
        }
        i++;
    }
    for(auto i:mp){
        if(i.second==1){
            cout<<i.first<<" ";
        }
    }*/
}

int main()
{
    int a[][N] = {{ 1, 2, 3, 20}, 
                     {5, 6, 20, 25}, 
                     {1, 3, 5, 6}, 
                     {6, 7, 8, 15}};

    unique_elements(a,4,4);
	cout<<endl;
    return 0;
}

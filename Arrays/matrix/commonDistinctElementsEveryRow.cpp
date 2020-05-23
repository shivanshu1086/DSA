#include <iostream>
#include <unordered_map>

#define MAX 100
using namespace std;

void commonDistinctElements(int a[][MAX], int n){
    unordered_map<int, int> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s[a[i][j]]++;
        }
    }
    for(auto i:s){
        if(i.second>=n){
            cout<<i.first<<" ";
        }
    }
}

int main()
{
    int a[][MAX] = {   {12, 1, 14, 3, 16}, 
        {14, 2, 1, 3, 35}, 
        {14, 1, 14, 3, 11}, 
        {14, 25, 3, 2, 1}, 
        {1, 18, 3, 21, 14}}; 
    int n = 5; 
    commonDistinctElements(a,n);
	cout<<endl;
    return 0;
}

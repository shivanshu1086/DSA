#include<iostream>
#include <unordered_set>
using namespace std;

void findPairs(int *a, int *b, int n, int m, int x){
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        set.insert(a[i]);
    }

    for(int i=0;i<m;i++){
        if(set.find(x-b[i])!=set.end()){
            cout<<"("<<x-b[i]<<","<<b[i]<<")"<<endl;
        }
    }
}


int main() {
    int arr1[] = {1, 2, 4, 5, 7}; 
    int arr2[] = {5, 6, 3, 4, 8}; 
    int x = 9; 
    int n = sizeof(arr1) / sizeof(int); 
    int m = sizeof(arr2) / sizeof(int); 
    findPairs(arr1, arr2, n, m, x);
    cout<<endl;
	return 0;
}
#include<iostream>
#include <unordered_map>

using namespace std;

void printFirstRepeating(int *a, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(int i=0;i<n;i++){
        if(mp[a[i]]>=2){
            cout<<a[i];
            return;
        }
    }
}


int main() {
    int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
    printFirstRepeating(arr, n);
    cout<<endl;
	return 0;
}
#include<iostream>
#include <unordered_map>

using namespace std;

void printPairs(int *a, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            mp[a[i]]++;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]<0){
            if(mp.find(abs(a[i]))!=mp.end()){
                cout<<a[i]<<","<<abs(a[i])<<endl;
            }
        }
    }
}

int main() {
    int arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printPairs(arr, n); 
    cout<<endl;
	return 0;
}
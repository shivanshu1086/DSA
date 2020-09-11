#include<iostream>
#include <unordered_map>

using namespace std;

void firstNonRepeating(int *a, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(int i=0;i<n;i++){
        if(mp.find(a[i])!=mp.end() && mp[a[i]]==1){
            cout<<a[i];
            return;
        }
    }
}


int main() {
    int arr[] = { 9, 4, 9, 6, 7, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    firstNonRepeating(arr, n);
    cout<<endl;
	return 0;
}
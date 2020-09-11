#include <iostream>
#include <unordered_map>
using namespace std;

int minDelete(int *a, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    int count = INT_MIN;
    for(auto i:mp){
        if(i.second>count){
            count = i.second;
        }
    }
    return n-count;
}

int main(){
    int arr[] = { 4, 3, 4, 4, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDelete(arr, n);
    cout<<endl;
    return 0;
}
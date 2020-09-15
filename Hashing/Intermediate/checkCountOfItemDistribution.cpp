#include <iostream>
#include <unordered_map>
using namespace std;

bool checkCount(int *a, int n, int k){
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(auto it:mp){
        if(it.second>2*k){
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = { 1, 1, 2, 3, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
    checkCount(arr, n, k) ? cout << "Yes"
                           : cout << "No";
    cout<<endl;
	return 0;
}
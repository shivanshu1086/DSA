#include <iostream>
#include <unordered_map>
using namespace std;

int longLenSub(int arr[], int n) 
{
    unordered_map<int, int> um;

    int longLen = 0;

    for(int i=0;i<n;i++){
        int len=0;

        if(um.find(arr[i]-1)!=um.end() && len < um[arr[i]-1]){
            len = um[arr[i]-1];
        }

        if(um.find(arr[i]+1)!=um.end() && len < um[arr[i]+1]){
            len = um[arr[i]+1];
        }

        um[arr[i]] = len+1;

        if(longLen<um[arr[i]]){
            longLen=um[arr[i]];
        }
    }
    return longLen;
}

int main() {
    int arr[] = {1, 2, 3, 2, 3, 7, 2, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Longest length subsequence = "
         << longLenSub(arr, n);
    cout<<endl;
	return 0;
}
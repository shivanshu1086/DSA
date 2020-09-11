#include<iostream>
#include <unordered_set>

using namespace std;


int findSum(int *arr, int n){
    int sum=0;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if (s.find(arr[i]) == s.end()) 
        { 
            sum += arr[i]; 
            s.insert(arr[i]); 
        } 
    }
    
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 1, 1, 4, 5, 6}; 
    int n = sizeof(arr)/sizeof(int); 
    cout << findSum(arr, n);
    cout<<endl;
	return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

long long int findSubarraySum(int arr[], int n) 
{
    int res = 0;

    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j]; 
            m[sum]++;
        }
    }

    for (auto x : m) 
        if (x.second == 1) 
            res += x.first; 
  
    return res;
}


int main() {
    int arr[] = { 3, 2, 3, 1, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findSubarraySum(arr, n);
    cout<<endl;
	return 0;
}
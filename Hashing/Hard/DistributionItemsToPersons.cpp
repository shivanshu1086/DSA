#include <iostream>
#include <unordered_map>
using namespace std;

bool checkCount(int *arr, int n, int k){
    unordered_map<int, int> hash;

    for (int i = 0; i < n; i++) 
        hash[arr[i]]++;

    for (auto x : hash) 
        if (x.second > 2 * k) 
            return false;

    return true;
}

int main() {
    int arr[] = {2, 3, 3, 5, 3, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
    checkCount(arr, n, k) ? cout << "Yes"
                           : cout << "No"; 
    cout<<endl;
	return 0;
}
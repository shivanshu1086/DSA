#include <iostream>
#include <unordered_map>
using namespace std;

void findLIS(int *A, int n){
    unordered_map<int, int> hash; 
  
    // Initialize result 
    int LIS_size = 1; 
    int LIS_index = 0; 
  
    hash[A[0]] = 1; 
  
    // iterate through array and find 
    // end index of LIS and its Size 
    for (int i = 1; i < n; i++) { 
        hash[A[i]] = hash[A[i] - 1] + 1; 
        if (LIS_size < hash[A[i]]) { 
            LIS_size = hash[A[i]]; 
            LIS_index = A[i]; 
        } 
    } 
  
    // print LIS size 
    cout << "LIS_size = " << LIS_size << "\n"; 
  
    // print LIS after setting start element 
    cout << "LIS : "; 
    int start = LIS_index - LIS_size + 1; 
    while (start <= LIS_index) { 
        cout << start << " "; 
        start++; 
    }
}

int main() {
    int A[] = {5, 7, 6, 7, 8}; 
    int n = sizeof(A) / sizeof(A[0]);
    findLIS(A, n);
    cout<<endl;
	return 0;
}
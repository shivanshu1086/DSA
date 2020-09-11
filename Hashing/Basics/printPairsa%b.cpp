#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findDivisors(int n) 
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) 
                v.push_back(i); 
            else { 
                v.push_back(i); 
                v.push_back(n / i); 
            }
        }
    }
    return v;
}

bool printPairs(int arr[], int n, int k) 
{
    unordered_map<int, bool> occ;
    for (int i = 0; i < n; i++) 
        occ[arr[i]] = true;
    
    bool isPairFound = false; 
    for(int i=0;i<n;i++){
        if (occ[k] && k < arr[i]) { 
            cout << "(" << k << ", " << arr[i] << ") "; 
            isPairFound = true; 
        }

        if(arr[i]>=k){
            vector<int> v = findDivisors(arr[i] - k);
            for (int j = 0; j < v.size(); j++) {
                if (arr[i] % v[j] == k && arr[i] != v[j] && occ[v[j]]) {
                    cout << "(" << arr[i] << ", "
                         << v[j] << ") "; 
                    isPairFound = true;
                }
            }
            v.clear();
        }
    }
    return isPairFound;
}

int main() {
    int arr[] = { 3, 1, 2, 5, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
  
    if (printPairs(arr, n, k) == false) 
        cout << "No such pair exists";
    cout<<endl;
	return 0;
}
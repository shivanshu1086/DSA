#include <iostream>
#include <unordered_set>
using namespace std;

int countSubsets(int *a, int n){
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            set.insert(a[i]);
        }
    }

    int ceven = set.size();
    return pow(2,ceven)-1;
}

int main() {
    int arr[] = {4, 2, 1, 9, 2, 6, 5, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Number of subsets = "
         << countSubsets(arr, n);
    cout<<endl;
	return 0;
}
#include <iostream>
#include <map>
#include <utility>
using namespace std;

bool findPairs(int *arr, int n){
    map<int, pair<int, int> > Hash;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = arr[i] + arr[j];
            if (Hash.find(sum) == Hash.end()) 
                Hash[sum] = make_pair(i, j);
            
            else{
                pair<int, int> pp = Hash[sum];

                cout << "(" << arr[pp.first] << ", " << arr[pp.second] 
                     << ") and (" << arr[i] << ", " << arr[j] << ")"; 
                return true;
            }
        }
    }
    cout << "No pairs found"; 
    return false;
}

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8}; 
    int n  =  sizeof arr / sizeof arr[0]; 
    findPairs(arr, n);
    cout<<endl;
	return 0;
}
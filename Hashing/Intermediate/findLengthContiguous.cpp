#include <iostream>
#include <set>
using namespace std;

int findLength(int arr[], int n) 
{
    int max_len=1;
    for(int i=0;i<n;i++){
        set<int>myset;
        myset.insert(arr[i]);

        int mn = arr[i];
        int mx = arr[i];

        for(int j=i+1;j<n;j++){
            if (myset.find(arr[j]) != myset.end()) 
                break;
            
            myset.insert(arr[j]); 
            mn = min(mn, arr[j]); 
            mx = max(mx, arr[j]);

            if (mx - mn == j - i) 
                max_len = max(max_len, mx - mn + 1); 
        }
    }
    return max_len;
}

int main() {
    int arr[] = {10, 12, 12, 10, 10, 11, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of the longest contiguous"
         << " subarray is " << findLength(arr, n);
    cout<<endl;
	return 0;
}
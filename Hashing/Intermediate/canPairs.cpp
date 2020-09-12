#include <iostream>
#include <unordered_map>
using namespace std;

bool canPairs(int *a, int n, int k){
    if (n & 1) 
        return false;
    
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) 
        freq[a[i] % k]++;

    for(int i=0;i<n;i++){
        int rem = a[i] % k;

        if(2*rem==k){
            if(freq[rem]%2!=0){
                return false;
            }
        }

        else if(rem==0){
            if(freq[rem] & 1){
                return false;
            }
        }
        else if(freq[rem]!=freq[k-rem]){
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] =  {92, 75, 65, 48, 45, 35}; 
    int k = 10; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    canPairs(arr, n, k)? cout << "True": cout << "False";
    cout<<endl;
	return 0;
}
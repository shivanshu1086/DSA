#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarrays(int arr[], int n){
    int difference = 0; 
    int ans = 0;

    int hash_positive[n+1], hash_negative[n+1];

    fill_n(hash_negative,n+1,0);
    fill_n(hash_positive,n+1,0);

    hash_positive[0]=1;

    for(int i=0;i<n;i++){
        if ((arr[i] & 1) == 1) 
            difference++; 
        else
            difference--;

        if (difference < 0) 
        { 
            ans += hash_negative[-difference]; 
            hash_negative[-difference]++; 
        } 
          
        // else use hash_positive 
        else
        { 
            ans += hash_positive[difference]; 
            hash_positive[difference]++; 
        }
    }
    return ans;
}

int main() {
    int arr[] = {3, 4, 6, 8, 1, 10, 5, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    // Printing total number of even-odd subarrays 
    cout << "Total Number of Even-Odd subarrays"
        " are " << countSubarrays(arr,n);
    cout<<endl;
	return 0;
}
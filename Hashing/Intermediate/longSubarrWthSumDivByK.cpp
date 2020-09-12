#include <iostream>
#include <unordered_map>
using namespace std;

int longSubarrWthSumDivByK(int arr[],  
                          int n, int k) 
{
    unordered_map<int, int> um;

    int mod_arr[n], max = 0; 
    int curr_sum = 0;

    for(int i=0;i<n;i++){
        curr_sum  += arr[i];
        mod_arr[i] = ((curr_sum%k)+k)%k;
    }

    for(int i=0;i<n;i++){
        if (mod_arr[i] == 0){
            max =i+1;
        }
        else if (um.find(mod_arr[i]) == um.end()) 
            um[mod_arr[i]] = i;
        
        else{
            if (max < (i - um[mod_arr[i]])) 
                max = i - um[mod_arr[i]];
        }
    }
    return max;
}

int main() {
    int arr[] = {2, 7, 6, 1, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
      
    cout << "Length = "
         << longSubarrWthSumDivByK(arr, n, k);
    cout<<endl;
	return 0;
}
#include <iostream>
#include <map>
using namespace std;

void subarrayDivisibleByK(int arr[], int n, int k) 
{
    map<int,int> mp;
    int s = 0, e = 0, maxs = 0, maxe = 0; 
    mp[arr[0] % k]++;

    for(int i=1;i<n;i++){
        int mod = arr[i] % k;
        while (mp[k - mod] != 0 || 
              (mod == 0 && mp[mod] != 0)) 
        { 
            mp[arr[s] % k]--; 
            s++; 
        }
        mp[mod]++; 
        e++;

        if ((e - s) > (maxe - maxs)) 
        { 
            maxe = e; 
            maxs = s; 
        }
    }
    cout << "The maximum size is "
         << maxe - maxs + 1 << " and "
         "the subarray is as follows\n"; 
  
    for (int i=maxs; i<=maxe; i++) 
        cout << arr[i] << " ";
}

int main() {
    int k = 3; 
    int arr[] = {5, 10, 15, 20, 25}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    subarrayDivisibleByK(arr, n, k);
    cout<<endl;
	return 0;
}
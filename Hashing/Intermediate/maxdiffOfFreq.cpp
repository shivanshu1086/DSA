#include <iostream>
#include <unordered_map>
using namespace std;

int maxdiff(int arr[], int n) 
{
    unordered_map<int, int> freq; 
  
    int dist[n];

    int j = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (freq.find(arr[i]) == freq.end()) 
            dist[j++] = arr[i]; 
  
        freq[arr[i]]++; 
    }

    sort(dist, dist + j);

    int min_freq = n+1;

    int ans = 0; 

    for (int i=0; i<j; i++) 
    { 
        int cur_freq = freq[dist[i]]; 
        ans = max(ans, cur_freq - min_freq); 
        min_freq = min(min_freq, cur_freq); 
    } 
  
    return ans;
}

int main() {
    int arr[] = { 3, 1, 3, 2, 3, 2 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << maxdiff(arr, n) << endl;
    cout<<endl;
	return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;
int countPairs(int arr[], int n) 
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) 
        mp[arr[i]]++;

    int ans = 0;

    for(auto it=mp.begin(); it!=mp.end(); it++){
        int count = it->second;
        ans += (count * (count - 1))/2;
    }
    return ans;
}

int main() {
    int arr[] = {1, 1, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << countPairs(arr, n) << endl;
    cout<<endl;
	return 0;
}
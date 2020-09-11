#include <iostream>
#include <unordered_map>
using namespace std;

int subset(int arr[], int n) 
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)  
        mp[arr[i]]++;
    
    int res = 0; 
    for (auto x : mp) 
       res = max(res, x.second);
    
    return res;
}

int main(){
    int arr[] = { 5, 6, 9, 3, 4, 3, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << subset(arr, n);
    cout<<endl;
    return 0;
}
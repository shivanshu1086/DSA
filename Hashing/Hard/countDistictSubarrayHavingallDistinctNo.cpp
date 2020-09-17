#include <iostream>
#include <unordered_map>
using namespace std;

int countDistictSubarray(int arr[], int n) 
{
    unordered_map<int, int>  vis;

    for(int i=0;i<n;i++){
        vis[arr[i]]=1;
    }
    int k = vis.size();

    vis.clear();

    int ans=0, right=0, window=0;
    for(int left=0;left<n;left++){
        while(right<n && window<k){
            ++vis[arr[right]];

            if(vis[arr[right]]==1){
                ++window;
            }

            ++right;
        }

        if(window==k){
            ans+=n-right+1;
        }

        --vis[arr[left]];

        if (vis[ arr[left] ] == 0) 
            --window;
    }
    return ans;
}

int main() {
    int arr[] = {2, 1, 3, 2, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << countDistictSubarray(arr, n);
    cout<<endl;
	return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;


int maxDistance(int *a, int n){
    unordered_map<int,int> mp;
    int max_overall=INT_MIN;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end()){
            mp[a[i]]=i;
        }
        else{
            max_overall = max(max_overall, i-mp[a[i]]);
        }  
    }

    return max_overall;
}


int main(){
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxDistance(arr, n);
    cout<<endl;
    return 0;
}
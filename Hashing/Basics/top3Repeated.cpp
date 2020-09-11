#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void top3Repeated(int *a, int n, int k=3){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for(auto i:mp){
        pq.push(make_pair(i.second,i.first));
        if(pq.size()>k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}


int main(){
    int arr[] = { 3, 4, 2, 3, 16, 3, 15, 
                  16, 15, 15, 16, 2, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    top3Repeated(arr, n);
    cout<<endl;
    return 0;
}
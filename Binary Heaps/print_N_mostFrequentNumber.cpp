#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<int,int> pof;

void print_N_mostFrequentNumber(int *a, int n, int k){
    priority_queue<pof,vector<pof>, greater<pof> > heap;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(auto i:mp){
        heap.push(make_pair(i.second,i.first));
        if(heap.size()>k){
            heap.pop();
        }
    }

    while(!heap.empty()){
        cout<<heap.top().second<<endl;
        heap.pop();
    }

}


int main(){
    int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
    print_N_mostFrequentNumber(arr, n, k);
    cout<<endl;
    return 0;
}
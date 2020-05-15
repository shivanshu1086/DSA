#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

bool compare(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    if(a.second.second==b.second.second){
        return a.second.first<b.second.first;
    }
    return a.second.second>b.second.second;
}

void sort_by_frequencies(int *a, int n){
    unordered_map<int,pair<int,int> > mp;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])!=mp.end()){
            mp[a[i]].second++;
        }
        else{
            mp[a[i]]=make_pair(i,1);
        }
    }
    vector<pair<int,pair<int,int> > >b;
    for(auto i:mp){
        b.push_back(make_pair(i.first,i.second));
    }
    stable_sort(b.begin(),b.end(),compare);
    for(int i=0;i<b.size();i++){
        int count=b[i].second.second;
        while(count--){
            cout<<b[i].first<<" ";
        }
    }
}

int main()
{
    int a[]={2, 5, 2, 8, 5, 6, 8, 8};
    int n=sizeof(a)/sizeof(a[0]);
    sort_by_frequencies(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

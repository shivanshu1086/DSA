#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
using namespace std;

void min_swaps_to_sort(int *a, int n){
    pair<int,int> temp[n];
    for(int i=0;i<n;i++){
        temp[i].first=a[i];
        temp[i].second=i;
    }
    sort(temp,temp+n);

    vector<bool> visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++){
        if(visited[i]|| temp[i].second==i){
            continue;
        }

        int count_size=0;
        int j=i;
        while(!visited[j]){
            visited[j]=1;
            j=temp[j].second;
            count_size++;
        }
        if(count_size>0){
            ans+=(count_size-1);
        }
    }
    cout<<ans;
}


int main()
{
    int a[]={1, 5, 4, 3, 2};
    int n=sizeof(a)/sizeof(a[0]);
    min_swaps_to_sort(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

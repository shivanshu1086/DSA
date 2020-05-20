#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>
using namespace std;

void subarray_with_given_sum(int *a, int n, int sum){
    int cur_max=a[0],start=0,i;
    for(int i=1;i<=n;i++){
        while(cur_max>sum && start<i-1){
            cur_max-=a[start++];
        }
        if(cur_max==sum){
            cout<<"Sum found "<<start<<" to "<<i-1;
            return;
        }
        if(i<n){
            cur_max+=a[i];
        }
    }
    cout<<"Not found";
}
//if array has negative elements too
void neg_too(int *a, int n, int sum){
    unordered_map<int,int> mp;
    int cur_sum=0;
    for(int i=0;i<n;i++){
        cur_sum+=a[i];
        if(cur_sum==sum){
            cout<<"0 to "<<i;
            return;
        }
        if(mp.find(cur_sum-sum)!=mp.end()){
            cout<<mp[cur_sum-sum]+1<<" to "<<i;
            return;
        }
        mp[cur_sum]=i;
    }
}

int main()
{
    int a[] ={10, 2, 2, 20, 10};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=32;
    subarray_with_given_sum(a,n,sum);
    // neg_too(a,n,sum);
	cout<<endl;
    return 0;
}

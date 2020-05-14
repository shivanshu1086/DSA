#include <iostream>
#include<vector>
#include <cmath>
#include <unordered_map>
using namespace std;
void longest_span_with_same_sum(bool *a1, bool *a2, int n){
    int max_length=0;
    int presum1=0,presum2=0;
    int diff[2*n+1];
    memset(diff,-1,sizeof(diff));
    for(int i=0;i<n;i++){
        presum1+=a1[i];
        presum2+=a2[i];

        int curr_diff=presum2-presum1;
        int diffIndex=n+curr_diff;
        if(curr_diff==0){
            max_length=i+1;
        }
        else if(diff[diffIndex]==-1){
            diff[diffIndex]=i;
        }
        else{
            int len=i-diff[diffIndex];
            if(len>max_length){
                max_length=len;
            }
        }
    }
    cout<<max_length;
}

//Hashing method

void hashing_method(bool *a1, bool *a2, int n){
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=a1[i]-a2[i];
    }
    unordered_map<int,int> mp;
    int sum=0,max_length=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            max_length=i+1;
        }
        if(mp.find(sum)!=mp.end()){
            max_length=max(max_length,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }
    }
    cout<<max_length;
}

int main()
{
    bool a1[]={0, 1, 0, 1, 1, 1, 1};
    bool a2[]={1, 1, 1, 1, 1, 0, 1};
    int n=sizeof(a1)/sizeof(a1[0]);
    // longest_span_with_same_sum(a1,a2,n);
    hashing_method(a1,a2,n);
	cout<<endl;
    return 0;
}

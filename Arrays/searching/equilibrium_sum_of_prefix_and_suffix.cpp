#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

void equilibrium_sum_of_prefix_and_suffix(int *a, int n){
    int prefix[n],suffix[n];
    int ans=INT_MIN;
    //prefix filling
    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    //suffix filling
    suffix[n-1]=a[n-1];
    if(suffix[n-1]==prefix[n-1]){
        ans=max(ans,prefix[n-1]);
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+a[i];
        if(suffix[i]==prefix[i]){
            ans=max(ans,prefix[i]);
        }
    }
    cout<<ans;
}

//most efficient
void efficient(int *a, int n){
    int sum=accumulate(a,a+n,0);
    int prefix=0;int res=INT_MIN;
    for(int i=0;i<n;i++){
        prefix+=a[i];
        if(prefix==sum){
            res=max(res,prefix);
        }
        sum-=a[i];
    }
    cout<<res;
}

int main()
{
    int a[] ={-2, 5, 3, 1, 2, 6, -4, 2};
    int n=sizeof(a)/sizeof(a[0]);
    // equilibrium_sum_of_prefix_and_suffix(a,n);
    efficient(a,n);
	cout<<endl;
    return 0;
}

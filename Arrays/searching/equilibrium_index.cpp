#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

void equilibrium_index(int *a, int n){
    int sum=accumulate(a,a+n,0);
    int prefix=0,res=INT_MIN;
    for(int i=0;i<n;i++){
        prefix+=a[i];
        if(prefix==sum){
            cout<<i;
            return;
        }
        sum-=a[i];
    }
    cout<<"-1";
}

int main()
{
    int a[] ={1, 2, 3};
    int n=sizeof(a)/sizeof(a[0]);
    equilibrium_index(a,n);
	cout<<endl;
    return 0;
}

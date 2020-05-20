#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>
using namespace std;

//with two pointer technique
void triplet_with_sum(int *a, int n, int sum){
    int l,r;
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        l=i+1;
        r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==sum){
                cout<<"Triplet is "<<a[i]<<","<<a[l]<<","<<a[r];
                return;
            }
            else if(a[i]+a[l]+a[r]<sum){
                l++;
            }
            else{
                r--;
            }
        }
    }
}

int main()
{
    int a[] = { 1, 4, 45, 6, 10, 8 } ;
    int n=sizeof(a)/sizeof(a[0]);
    int sum=22;
    triplet_with_sum(a,n,sum);
	cout<<endl;
    return 0;
}

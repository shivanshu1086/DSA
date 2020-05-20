#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>
using namespace std;

//with two pointer technique
void triplets_with_zero_sum(int *a, int n, int sum){
    int l,r;
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        l=i+1;
        r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==sum){
                cout<<"Triplet is "<<a[i]<<","<<a[l]<<","<<a[r];
                l++;
                r--;
                cout<<endl;
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
    int a[] = {0, -1, 2, -3, 1} ;
    int n=sizeof(a)/sizeof(a[0]);
    int sum=0;
    triplets_with_zero_sum(a,n,sum);
	cout<<endl;
    return 0;
}

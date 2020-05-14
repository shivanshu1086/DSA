#include <iostream>
#include<vector>
using namespace std;

void subarray_with_max_sum(int *a, int n){
    int max=0;
    int max_so_far=0;
    int l=0,r=0,start=0;
    for(int i=0;i<n;i++){
        max+=a[i];
        if(max<0){
            max=0;
            start=i+1;
        }
        if(max>max_so_far){
            max_so_far=max;
            l=start;
            r=i;
        }
    }
    cout<<max_so_far<<" : "<<l<<" to "<<r;
}


int main()
{
    int a[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
    int n=sizeof(a)/sizeof(a[0]);
    subarray_with_max_sum(a,n);
	cout<<endl;
    return 0;
}

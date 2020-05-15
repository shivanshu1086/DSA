#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

void segerate_ones_zeros(int *a, int n){
    int start=0;
    int end=n-1;
    while(start<end){
        if(a[start]==1){
            swap(a[start],a[end]);
            end--;
        }
        else{
            start++;
        }
    }
}

int main()
{
    int a[]={ 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1 };
    int n=sizeof(a)/sizeof(a[0]);
    segerate_ones_zeros(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
	cout<<endl;
    return 0;
}

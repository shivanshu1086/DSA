#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

void fixed_point(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[i]==i){
            cout<<a[i];
            return;
        }
    }
    cout<<"-1";
}

int binarysearch(int *a, int low, int high){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==mid){
            return mid;
        }
        else if(mid>a[mid]){
            return binarysearch(a,mid+1,high);
        }
        else{
            return binarysearch(a,low,mid-1);
        }
    }
    return -1;
}

int main()
{
    int a[] ={-10, -1, 0, 1, 3, 5, 30, 50, 100};
    int n=sizeof(a)/sizeof(a[0]);
    fixed_point(a,n);
    cout<<endl;
    cout<<a[binarysearch(a,0,n-1)];
	cout<<endl;
    return 0;
}

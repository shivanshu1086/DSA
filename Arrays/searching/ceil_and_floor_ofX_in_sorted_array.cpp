#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

int ceil_and_floor_ofX_in_sorted_array(int *a, int low, int high, int x){
    if(x<=a[low]){
        return low;
    }
    if(x>a[high]){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(a[mid]==x){
        return mid;
    }
    else if(x>a[mid]){
        if(mid+1<=high && a[mid+1]>=x){
            return mid+1;
        }
        else{
            return ceil_and_floor_ofX_in_sorted_array(a,mid+1,high,x);
        }
    }
    else{
        if(mid-1>=low && a[mid-1]<x){
            return mid;
        }
        else{
            return ceil_and_floor_ofX_in_sorted_array(a,low,mid-1,x);
        }
    }
}

int main()
{
    int a[] ={1, 2, 8, 10, 10, 12, 19};
    int n=sizeof(a)/sizeof(a[0]);
    int x=3;
    int ans=ceil_and_floor_ofX_in_sorted_array(a,0,n-1,x);
    if(ans!=-1){
        cout<<"Ceil of "<<x<<" is "<<a[ans]<<" and floor is "<<a[ans-1];
    }
    else{
        cout<<"Ceil Not found both";
    }
	cout<<endl;
    return 0;
}

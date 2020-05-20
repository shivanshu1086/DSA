#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

void majority_in_sorted_array(int *a, int n, int x){
    for(int i=0;i<n;i++){
        if(a[i]==x && a[i+(n/2)]==x && i+(n/2)<n){
            cout<<x<<" is major";
            return;
        }
    }
    cout<<x<<" is not a major";
}

//binary search implementation

int binarysearch(int *a, int low, int high, int x){
    if(low<=high){
        int mid=low+(high-low)/2;
        if((mid == 0 || x > a[mid-1]) && (a[mid] == x)){
            return mid;
        }
        else if(x>a[mid]){
            return binarysearch(a,mid+1,high,x);
        }
        else{
            return binarysearch(a,low,mid-1,x);
        }
    }
    else{
        return -1;
    }
}

void is_major_using_binary_search(int *a, int n, int x){
    int i=binarysearch(a,0,n-1,x);
    if(i==-1){
        cout<<"Not found";
    }
    if(a[i]==x && a[i+(n/2)]==x && i+(n/2)<n){
        cout<<x<<" is major";
    }
    else{
        cout<<"Not found";
    }
}

int main()
{
    int a[] ={1, 2, 3, 3, 3, 3, 10};
    int n=sizeof(a)/sizeof(a[0]);
    majority_in_sorted_array(a,n,3);
    cout<<endl;
    is_major_using_binary_search(a,n,3);
	cout<<endl;
    return 0;
}

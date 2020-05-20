#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

int findPeak(int arr[], int n)  
{  
    //first or last element is peak element 
    if(arr[0] > arr[1]) 
      return 0; 
    if(arr[n-1] > arr[n-2]) 
      return n-1; 
  
    //check for every other element 
    for(int i=1 ; i < n-1 ; i++) 
    { 
      //check if the neighbours are smaller 
      if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) 
        return i; 
    } 
}

//O(logn) approach
int findpeak(int *a, int start, int end, int n){
    int mid=start+(end-start)/2;
    if((mid==0||a[mid-1]<=a[mid])&&(mid==n-1||a[mid+1]<=a[mid])){
        return  mid;
    }
    else if(mid>0 && a[mid-1]>a[mid]){
        return findpeak(a,start,mid-1,n);
    }
    else{
        return findpeak(a,mid+1,end,n);
    }
}

int main()
{
    int a[] ={1, 3, 20, 4, 1, 0};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<findpeak(a,0,n-1,n);
	cout<<endl;
    return 0;
}

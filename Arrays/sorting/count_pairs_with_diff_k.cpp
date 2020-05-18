#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k) 
{ 
    int count = 0; 
    sort(arr, arr+n);  // Sort array elements 
  
    int l = 0; 
    int r = 0; 
    while(r < n) 
    { 
         if(arr[r] - arr[l] == k) 
        { 
              count++; 
              l++; 
              r++; 
        } 
         else if(arr[r] - arr[l] > k) 
              l++; 
         else // arr[r] - arr[l] < sum 
              r++; 
    }    
    return count; 
}//another method

int binary_search(int *a, int start, int end, int x){
    if(end>=start){
        int mid=start+(end-start)/2;
        if(x==a[mid]){
            return mid;
        }
        if(x>a[mid]){
            return binary_search(a,mid+1,end,x);
        }
        else{
            return binary_search(a,start,mid-1,x);
        }
    }
    return -1;
}

void count_pairs_with_diff_k(int *a, int n, int k){
    int count=0,i;
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        if(binary_search(a,i+1,n-1,a[i]+k)!=-1){
            count++;
        }
    }
    cout<<count;
}

int main()
{
    int a[] = {1, 5, 3, 4, 2}; 
    int n = sizeof(a)/sizeof(a[0]);
    count_pairs_with_diff_k(a,n,3);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

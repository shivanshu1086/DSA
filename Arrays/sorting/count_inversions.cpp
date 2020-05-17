#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
}
//O(n^2)

int merge(int *a, int *temp, int left, int mid, int right){
    int i,j,k;
    int inv_count=0;
    i=left;
    j=mid;
    k=left;
    while((i<=mid-1)&&(j<=right)){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            inv_count+=(mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(i=left;i<=right;i++){
        a[i]=temp[i];
    }
    return inv_count;
}

int mergeSort(int *a, int *temp, int left, int right){
    int mid,inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        inv_count+=mergeSort(a,temp,left,mid);
        inv_count+=mergeSort(a,temp,mid+1,right);

        inv_count+=merge(a,temp,left,mid+1,right);
    }
    return inv_count;
}

void count_inversions(int *a, int n){
    int temp[n];
    cout<<mergeSort(a,temp,0,n-1);
}

int main()
{
    int a[]={ 1, 20, 6, 4, 5 };
    int n=sizeof(a)/sizeof(a[0]);
    count_inversions(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void minimum_unsorted_subarray(int *a, int n){
    int start=0,end=n-1,i,max,min;
    for(start=0;start<n-1;start++){
        if(a[start]>a[start+1]){
            break;
        }
    }
    if (start == n-1) 
    { 
        cout << "The complete array is sorted"; 
        return; 
    }
    for(end=n-1;end>0;end--){
        if(a[end]<a[end-1]){
            break;
        }
    }
    max=a[start];min=a[start];
    for(i=start+1;i<=end;i++){
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    for(i=0;i<start;i++){
        if(a[i]>min){
            start=i;
            break;
        }
    }
    for(i=n-1;i>=end+1;i--){
        if(a[i]<max){
            end=i;
            break;
        }
    }
    cout<<start<<" to "<<end<<endl;
}


int main()
{
    int a[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n=sizeof(a)/sizeof(a[0]);
    minimum_unsorted_subarray(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

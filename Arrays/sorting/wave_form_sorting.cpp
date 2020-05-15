#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

void wave_form_sorting(int *a, int start, int end){
    int n=end+1;
    sort(a,a+n);
    int mid=n/2;
    int left=mid-1;
    int right=mid;
    while(right<n && left>=0){
        cout<<a[right++]<<" "<<a[left--]<<" ";
    }
    if(n%2!=0){
        cout<<a[n-1];
    }

    //O(n) approach
    /*
    for(int i=0;i<n;i+=2){
        if(i>0 && a[i-1]>a[i]){
            swap(a[i-1],a[i]);
        }
        if(i<n-1 && a[i+1]>a[i]){
            swap(a[i+1],a[i]);
        }
    }
    */
}


int main()
{
    int a[]={3, 6, 5, 10, 7, 20};
    int n=sizeof(a)/sizeof(a[0]);
    wave_form_sorting(a,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

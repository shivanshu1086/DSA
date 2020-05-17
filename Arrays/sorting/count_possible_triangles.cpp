#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void count_possible_triangles(int *a, int n){
    sort(a,a+n);
    int count=0;
    for(int i=n-1;i>0;i--){
        int l=0;
        int r=i-1;
        while(l<r){
            if(a[l]+a[r]>a[i]){
                count+=(r-l);
                r--; 
            }
            else{
                l++;
            }
        }
    }
    cout<<count;
}


int main()
{
    int a[]={10, 21, 22, 100, 101, 200, 300};
    int n=sizeof(a)/sizeof(a[0]);
    count_possible_triangles(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void construct_pair_sum_array(int *a, int n){
    for(int i=0;i<n;i++){
        int d=i+1;
        while(d<n){
            cout<<a[i]+a[d]<<" ";
            d++;
        }
    }
}


int main()
{
    int a[] = {6, 8, 3, 4}; 
    int n = sizeof(a)/sizeof(a[0]);
    construct_pair_sum_array(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

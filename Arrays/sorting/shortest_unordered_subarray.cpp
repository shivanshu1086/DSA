#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
using namespace std;

bool decreasing(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[i]<a[i+1]){
            return false;
        }
    }
    return true;
}

bool increasing(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}

void shortest_unordered_subarray(int *a, int n){
    if(increasing(a,n)||decreasing(a,n)){
        cout<<"0";
    }
    else{
        cout<<"3";
    }
}


int main()
{
    int a[]={ 7, 9, 10, 8, 11 };
    int n=sizeof(a)/sizeof(a[0]);
    shortest_unordered_subarray(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
using namespace std;

void print_union(int *a, int *b, int n, int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            cout<<a[i++]<<" ";
        }
        else if(a[i]>b[j]){
            cout<<b[j++]<<" ";
        }
        else{
            cout<<a[i++]<<" ";
            j++;
        }
    }
    while(i<n){
        cout<<a[i++]<<" ";
    }
    while(j<m){
        cout<<b[j++]<<" ";
    }
}

void print_intersection(int *a, int *b, int n, int m){
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            cout<<a[i++]<<" ";
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int main()
{
    int a[]={2, 5, 6};
    int n=sizeof(a)/sizeof(a[0]);
    int b[]={4, 6, 8, 10};
    int m=sizeof(b)/sizeof(b[0]);
    print_union(a,b,n,m);
    cout<<endl;
    print_intersection(a,b,n,m);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

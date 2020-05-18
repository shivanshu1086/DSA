#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void product_of_max_and_min_in_twoArray(int *a, int *b, int n, int m){
    int max=a[0];
    int min=b[0];
    int i;
    for(i=1;i<n && i<m;i++){
        if(a[i]>max){
            max=a[i];
        }
        if(b[i]<min){
            min=b[i];
        }
    }
    while(i<n){
        if(a[i]>max){
            max=a[i];
        }
        i++;
    }
    while(i<m){
        if(b[i]<min){
            min=b[i];
        }
        i++;
    }

    cout<<max*min;
}


int main()
{
    int a[] = {5, 7, 9, 3, 6, 2};
    int n=sizeof(a)/sizeof(a[0]);
    int b[]={1, 2, 6, -1, 0, 9};
    int m=sizeof(b)/sizeof(b[0]);
    product_of_max_and_min_in_twoArray(a,b,n,m);
	cout<<endl;
    return 0;
}

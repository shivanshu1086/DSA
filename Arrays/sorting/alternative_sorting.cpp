#include <iostream>
#include<vector>
#include <cmath>

using namespace std;

void alternative_sorting(int *a, int n){
    sort(a,a+n);
    int start=0;
    int end=n-1;
    while(start<end){
        cout<<a[end--]<<" "<<a[start++]<<" ";
    }
    if(n%2!=0){
        cout<<a[start];
    }
}

int main()
{
    int a[]={7, 1, 2, 3, 4, 5, 6};
    int n=sizeof(a)/sizeof(a[0]);
    alternative_sorting(a,n);
	cout<<endl;
    return 0;
}

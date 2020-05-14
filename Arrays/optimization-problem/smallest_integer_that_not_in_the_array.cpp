#include <iostream>
#include<vector>
using namespace std;


void smallest_integer_that_not_in_the_array(int *a, int n){//number that cant be formed with the array elements
    int res=1;
    for(int i=0;i<n&&a[i]<=res;i++){
        res=res+a[i];
    }
    cout<<res;
}

int main()
{
    int a[]={1, 4, 5, 9, 1};
    int n=sizeof(a)/sizeof(a[0]);
    smallest_integer_that_not_in_the_array(a,n);
	cout<<endl;
    return 0;
}

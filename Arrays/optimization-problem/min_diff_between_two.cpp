#include <iostream>
#include<vector>
using namespace std;

void min_diff_between_two(int *a, int n){
    sort(a,a+n);
    int min_so_far=INT_MAX;
    for(int i=0;i<n-1;i++){
        min_so_far=min(min_so_far,a[i+1]-a[i]);
    }
    cout<<min_so_far;
}


int main()
{
    int a[]={30, 5, 20, 9};
    int n=sizeof(a)/sizeof(a[0]);
    min_diff_between_two(a,n);
	cout<<endl;
    return 0;
}

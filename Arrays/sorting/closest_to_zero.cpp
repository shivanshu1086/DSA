#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
using namespace std;

bool compare(int a, int b){
    return abs(a)<abs(b);
}

void closest_to_zero(int *a, int n){
    sort(a,a+n,compare);
    int min_sum=INT_MAX;
    int x,y;
    for(int i=1;i<n;i++){
        if(abs(a[i-1]+a[i])<=min_sum){
            min_sum=abs(a[i-1]+a[i]);
            x=i-1;
            y=i;
        }
    }
    cout<<a[x]<<" "<<a[y]<<" "<<min_sum;
}


int main()
{
    int a[]={1, 60, -10, 70, -80, 85};
    int n=sizeof(a)/sizeof(a[0]);
    closest_to_zero(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

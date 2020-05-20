#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

void leaders_ele(int *a, int n){
    int maxele=a[n-1];
    cout<<maxele<<" ";
    for(int i=n-2;i>=0;i--){
        if(a[i]>maxele){
            maxele=a[i];
            cout<<maxele<<" ";
        }
    }
}

int main()
{
    int a[] ={16, 17, 4, 3, 5, 2};
    int n=sizeof(a)/sizeof(a[0]);
    leaders_ele(a,n);
	cout<<endl;
    return 0;
}

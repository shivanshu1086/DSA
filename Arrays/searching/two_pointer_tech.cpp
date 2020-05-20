#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

bool pair_exists(int *a, int n, int x){
    int i=0,j=n-1;
    while(i<j){
        if(a[i]+a[j]==x){
            return true;
        }
        else if(a[i]+a[j]<x){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main()
{
    int a[] ={10,20,35,50,70,80};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<boolalpha<<pair_exists(a,n,70);
	cout<<endl;
    return 0;
}

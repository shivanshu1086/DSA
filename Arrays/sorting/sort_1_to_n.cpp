#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

void sort_1_to_n(int *a, int n){
    for(int i=0;i<n;i++){
        while(a[i]!=i+1){
            swap(a[i],a[a[i]-1]);
        }
    }
    /*
    or we can do
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    */
}

int main()
{
    int a[]={ 10, 7, 9, 2, 8, 3, 5, 4, 6, 1 };
    int n=sizeof(a)/sizeof(a[0]);
    sort_1_to_n(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
	cout<<endl;
    return 0;
}

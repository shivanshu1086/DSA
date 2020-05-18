#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void print_all_distinct(int *a, int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(auto i:s){
        cout<<i<<" ";
    }
}

void another_method(int *a, int n){
    sort(a,a+n);
    for(int i=0;i<n;i++){
        while(i<n-1 && a[i]==a[i+1]){
            i++;
        }
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[] = {12, 10, 9, 45, 2, 10, 10, 45}; 
    int n = sizeof(a)/sizeof(a[0]);
    print_all_distinct(a,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_set>
using namespace std;

void pair_for_sum(int *a, int n, int k){
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<r){
        if(a[l]+a[r]==k){
            cout<<"Found pair";
            return;
        }
        else  if(a[l]+a[r]<k){
            l++;
        }
        else{
            r--;
        }
    }
}

void efficient_method(int *a, int n, int sum){
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        int temp=sum-a[i];
        if(s.find(temp)!=s.end()){
            cout<<"Pair found"<<" "<<a[i]<<" and "<<temp;
            return;
        }
        s.insert(a[i]);
    }
}

int main()
{
    int a[] = {0, -1, 2, -3, 1};
    int n=sizeof(a)/sizeof(a[0]);
    // pair_for_sum(a,n,-2);
    efficient_method(a,n,-2);
	cout<<endl;
    return 0;
}

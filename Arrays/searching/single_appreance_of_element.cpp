#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
using namespace std;

void single_appreance_of_element(int *a, int n){
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    vector<int>v;
    for(auto i:m){
        // cout<<i.first<<" "<<i.second<<endl;
        v.push_back(i.first);
    }
    cout<<v[v.size()-1];
}

void efficient_approach(int *a, int n){
    int res=a[0];
    for(int i=1;i<n;i++){
        res=res^a[i];//XOR of a number itself is 0 and with 0 is number itself
    }
    cout<<res;
}

int main()
{
    int a[] ={7, 3, 5, 4, 5, 3, 4};
    int n=sizeof(a)/sizeof(a[0]);
    // single_appreance_of_element(a,n);
    efficient_approach(a,n);
	cout<<endl;
    return 0;
}

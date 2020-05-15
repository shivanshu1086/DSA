#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

void absolute_diff_sorting(int *a, int n, int x){
    multimap<int,int> mp;//self balanced bst
    //insertion
    for(int i=0;i<n;i++){
        mp.insert(make_pair(abs(x-a[i]),a[i]));
    }

    //storing the values in the array back
    int j=0;
    for(auto i:mp){
        a[j++]=i.second;
    }
}

int main()
{
    int a[]={10, 5, 3, 9 ,2};
    int n=sizeof(a)/sizeof(a[0]);
    absolute_diff_sorting(a,n,7);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
	cout<<endl;
    return 0;
}

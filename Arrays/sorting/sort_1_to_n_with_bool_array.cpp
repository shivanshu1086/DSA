#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

void sort_1_to_n_with_bool_array(int *a, int n, int *b){
    for(int i=0;i<n-1;i++){
        if(b[i]){
            if(a[i]!=i+1){
                swap(a[i],a[i+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            cout<<"A can't be sorted";
            return;
        }
    }
    cout<<"A can be sorted";
}

int main()
{
    int a[]={2, 3, 1, 4, 5, 6};
    int b[]={ 0, 1, 1, 1, 1 };
    int n=sizeof(a)/sizeof(a[0]);
    sort_1_to_n(a,n,b);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
	cout<<endl;
    return 0;
}

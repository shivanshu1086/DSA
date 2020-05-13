#include <iostream>
#include<vector>
using namespace std;

void max_sum_increasing_subsequence(int *a, int n){
    int *prefix=new int[n];
    for(int i=0;i<n;i++){
        prefix[i]=a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]&&prefix[i]<prefix[j]+a[i]){
                prefix[i]=prefix[j]+a[i];
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix[i]>maxi){
            maxi=prefix[i];
        }
    }
    delete [] prefix;
    cout<<maxi;
}


int main()
{
    int a[]={1, 101, 2, 3, 100, 4, 5};
    int n=sizeof(a)/sizeof(a[0]);
    max_sum_increasing_subsequence(a,n);
	cout<<endl;
    return 0;
}
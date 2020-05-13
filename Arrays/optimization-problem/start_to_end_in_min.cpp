#include <iostream>
#include<vector>
using namespace std;

void start_to_end_in_min(int *a, int n){
    int *prefix=new int[n];
    for(int i=0;i<n;i++){
        prefix[i]=INT_MAX;
    }
    prefix[0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i<=j+a[j]){
                prefix[i]=min(prefix[i],prefix[j]+1);
            }
        }
    }
    int ans=prefix[n-1];
    delete [] prefix;
    cout<<ans;
}


int main()
{
    int a[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n=sizeof(a)/sizeof(a[0]);
    start_to_end_in_min(a,n);
	cout<<endl;
    return 0;
}
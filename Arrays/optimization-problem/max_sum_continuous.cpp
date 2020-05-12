#include <iostream>
#include<vector>
using namespace std;

void kadane_s_algo(int *a, int n){
    int cursum=0;
    int sum=0;
    int currl=0,currr=0,s=0;
    for(int i=0;i<n;i++){
        sum=a[i]+sum;
        if(sum>cursum){
            cursum=sum;
            currl=s;
            currr=i;
        }
        if(sum<0){
            sum=0;
            s=i+1;
        }
    }
    cout<<"starting from "<<currl<<" to "<<currr<<" : "<<cursum;
}

int main()
{
    int a[]={-2,-3,4,-1,-2,1,5,-3};
    int n=sizeof(a)/sizeof(a[0]);
    kadane_s_algo(a,n);
	cout<<endl;
    return 0;
}
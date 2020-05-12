#include <iostream>
#include<vector>
using namespace std;

void max_sum(int *a, int n){
    int *profit=new int[n];
    for(int i=0;i<n;i++){
        profit[i]=0;
    }
    
    int max_price=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>max_price){
            max_price=a[i];
        }
        profit[i]=max(profit[i+1],max_price-a[i]);
    }//max earn for 1 day

    int min_price=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min_price){
            min_price=a[i];
        }
        profit[i]=max(profit[i-1],profit[i]+(a[i]-min_price));
    }//max earn for 2nd day
    int res=profit[n-1];
    delete [] profit;
    cout<<res;
}

int main()
{
    int a[]={10, 22, 5, 75, 65, 80};
    int n=sizeof(a)/sizeof(a[0]);
    max_sum(a,n);
	cout<<endl;
    return 0;
}
#include <iostream>
#include<vector>
using namespace std;

void min_average(int *a, int n, int k){
    float sum=0;
    int range=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    int min_sum=sum;
    for(int i=k;i<n;i++){
        sum=sum+a[k]-a[i-k];
        if(sum<min_sum){
            min_sum=sum;
            range=(i-k+1);
        }
        
    }
    cout<<range<<" "<<range+k-1;
}

int main()
{
    int a[]={3, 7, 90, 20, 10, 50, 40};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    min_average(a,n,k);
	cout<<endl;
    return 0;
}
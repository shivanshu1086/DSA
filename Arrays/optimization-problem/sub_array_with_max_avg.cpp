#include <iostream>
#include<vector>
using namespace std;

void sub_array_with_max_avg(int *a, int n, int k){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    int cur_sum=sum;
    int range;
    for(int i=k;i<n;i++){
        cur_sum+=a[i]-a[i-k];
        if(cur_sum>sum){
            sum=cur_sum;
            range=i-k+1;
        }
    }
    cout<<range<<" to "<<range+k-1<< ' '<<sum;
}


int main()
{
    int a[]={1, 12, -5, -6, 50, 3};
    int n=sizeof(a)/sizeof(a[0]);
    sub_array_with_max_avg(a,n,4);
	cout<<endl;
    return 0;
}

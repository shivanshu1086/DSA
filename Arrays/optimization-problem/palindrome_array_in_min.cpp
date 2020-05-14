#include <iostream>
#include<vector>
using namespace std;

void palindrome_array_in_min(int *a,int start, int end){
    int n=end+1;
    if(n%2==0){
        int mid=start+(end-start)/2;
        int count=0;
        for(int i=mid,j=mid+1;i>=0&&j<n;i--,j++){
            if(a[i]!=a[j]){
                int sum=a[i]+a[j];
                a[i]=sum;
                a[j]=sum;
                count++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<count;
    }
    else{
        int mid=start+(end-start)/2;
        int count=0;
        for(int i=mid-1,j=mid+1;i>=0&&j<n;i--,j++){
            if(a[i]!=a[j]){
                int sum=a[i]+a[j];
                a[i]=sum;
                a[j]=sum;
                count++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<count;
    }
}


int main()
{
    int a[]={1, 4, 5, 9, 1};
    int n=sizeof(a)/sizeof(a[0]);
    palindrome_array_in_min(a,0,n-1);
	cout<<endl;
    return 0;
}

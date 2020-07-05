#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

void get_largest_divisible_by3(int a[], int n){
    int initial_sum=accumulate(a,a+n,0);
    if(initial_sum%3==0){
        for(int i=n-1;i>=0;i--){
            cout<<a[i];
        }
        return;
    }
    int i=0;
    while(initial_sum%3!=0){
        initial_sum-=a[i++];
    }
    i--;
    string s="";
    for(int j=n-1;j>i;j--){
        s+=to_string(a[j]);
    }
    int count_zeros=0;
    for(int k=0;k<=i;k++){
        if(a[k]==0){
            count_zeros++;
        }
    }
    while(count_zeros--){
        s+=to_string(0);
    }
    cout<<s;
}

int main(){
    int a[]={8,1,7,6,0};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    get_largest_divisible_by3(a,n);
    cout<<endl;
	return 0;
}
#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void print_0_1_2_sorted(int *a, int n){
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        switch (a[i])
        {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        default:
            break;
        }
    }
    int i=0;
    while(count0>0){
        a[i++]=0;
        count0--;
    }
    while(count1>0){
        a[i++]=1;
        count1--;
    }
    while(count2>0){
        a[i++]=2;
        count2--;
    }
}


int main()
{
    int a[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n=sizeof(a)/sizeof(a[0]);
    print_0_1_2_sorted(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
	cout<<endl;
    return 0;
}

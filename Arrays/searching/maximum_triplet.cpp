#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <numeric>
using namespace std;

void maximum_triplet(int *a, int n){
    int cur_max=0;
    for(int i=0;i<3;i++){
        cur_max+=a[i];
    }
    int max_so_far=cur_max;
    for(int i=3;i<n;i++){
        cur_max+=a[i]-a[i-3];
        max_so_far=max(max_so_far,cur_max);
    }
    cout<<max_so_far;
}
//if order does not matters
void with_out_order(int *a, int n){
    int maxA=INT_MIN,maxB=INT_MIN,maxC=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>maxA){
            maxC=maxB;
            maxB=maxA;
            maxA=a[i];
        }
        else if(a[i]>maxB){
            maxC=maxB;
            maxB=a[i];
        }
        else if(a[i]>maxC){
            maxC=a[i];
        }
    }
    cout<<maxA+maxB+maxC;
}

int main()
{
    int a[] ={1, 0, 8, 6, 4, 2} ;
    int n=sizeof(a)/sizeof(a[0]);
    maximum_triplet(a,n);
	cout<<endl;
    return 0;
}

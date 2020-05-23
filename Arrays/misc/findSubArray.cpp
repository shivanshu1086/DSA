#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int findSubArray(int *a, int n, int k){
    int start=0,endval=0,p=1,countOnes=0,res=0;

    while(endval<n){
        p*=a[endval];

        if(p>k){
            while(start<=endval && p>k){
                p/=a[start];
                start++;
            }
        }

        if(p==k){
            countOnes=0;
            while(endval+1<n && a[endval+1]==1){
                countOnes++;
                endval++;
            }
            res+=(countOnes+1);

            while(start<=endval && a[start]==1 && k!=1){
                res+=(countOnes+1);
                start++;
            }
            p/=a[start];
            start++;
        }
        endval++;
    }
    return res;
}

int main()
{
    int a[] = { 2, 1, 1, 1, 4, 5};
    int n=sizeof(a)/sizeof(a[0]);
    int k=4;
    cout<<findSubArray(a,n,k);
	cout<<endl;
    return 0;
}

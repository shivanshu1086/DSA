#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

int fact(int x){
    return (x==0)?1:x*fact(x-1);
}

void find_two_repeating(int *a, int size){
    int s=0;
    int p=1;
    int x,y;
    int D;
    int n=size-2,i;
    for(int i=0;i<size;i++){
        s+=a[i];
        p*=a[i];
    }
    s=s-n*(n+1)/2;
    p=p/fact(n);
    D=sqrt(s*s-4*p);
    x=(D+s)/2;
    y=(s-D)/2;
    cout<<x<<" "<<y;
}

void another_method(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[abs(a[i])]<0){
            cout<<abs(a[i])<<" ";
        }
        else{
            a[abs(a[i])]=-a[abs(a[i])];
        }
    }
}

int main()
{
    int a[] ={4, 2, 4, 5, 2, 3, 1};
    int n=sizeof(a)/sizeof(a[0]);
    find_two_repeating(a,n);
    cout<<endl;
    another_method(a,n);
	cout<<endl;
    return 0;
}

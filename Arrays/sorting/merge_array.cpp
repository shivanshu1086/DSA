#include <iostream>
#include<vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define NA -1

void movetoend(int *a, int mn){
    int j=mn-1;
    for(int i=mn-1;i>=0;i--){
        if(a[i]!=NA){
            a[j--]=a[i];
        }
    }
}

void mergearray(int *a, int *b, int m, int n){
    int i=n;//from where a array starts
    int j=0;//from where b array starts
    int k=0;
    while(k<(m+n)){
        //now take the value from a array if it is less than b
        if((i<(m+n) && a[i]<=b[j])||(j==n)){//if b array gets empty
            a[k]=a[i];
            k++;
            i++;
        }
        else{
            a[k]=b[j];
            k++;
            j++;
        }
    }
}

void merge_array(int *a, int *b, int mn, int n, int m){
    /*int j=0;
    for(int i=0;i<mn;i++){
        if(a[i]==NA){
            a[i]=b[j++];
        }
    }//O(nlogn)
    sort(a,a+mn);*/
    //O(m+n)
    movetoend(a,mn);//moving all elements to the end
    mergearray(a,b,m,n);
}


int main()
{
    int a[]={2, 8, NA, NA, NA, 13, NA, 15, 20};
    int mn=sizeof(a)/sizeof(a[0]);
    int b[]={5, 7, 9, 25};
    int n=sizeof(b)/sizeof(b[0]);
    int m=mn-n;
    merge_array(a,b,mn,n,m);
    for(int i=0;i<mn;i++){
        cout<<a[i]<<" ";
    }
	cout<<endl;
    return 0;
}

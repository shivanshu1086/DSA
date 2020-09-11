#include <iostream>
#define MAX 1000
using namespace std;

bool has[MAX+1][2];

void insertion(int *arr1, int n){
    for(int i=0;i<n;i++){
        if(arr1[i]>=0){
            has[arr1[i]][0] = 1;
        }
        else{
            has[abs(arr1[i])][1] = 1;
        }
    }
}

bool isSubset(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[i]<0){
            if(has[abs(a[i])][1]==0){
                return false;
            }
        }
        else{
            if(has[a[i]][0]==0){
                return false;
            }
        }
    }
    return true;
}


int main(){
    int arr1[] = {11, 1, 13, 21, 3, 7}; 
    int arr2[] = {11, 3, 7, 1};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    insertion(arr1,n);

    if(isSubset(arr2, m)) 
    printf("arr2 is a subset of arr1"); 
    else
    printf("arr2 is not a subset of arr1");
    cout<<endl;
    return 0;
}
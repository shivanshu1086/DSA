#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void relativeComponent(int *a, int *b, int n, int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }

        else if(a[i]>b[j]){
            j++;
        }

        else if(a[i]==b[j]){
            i++;
            j++;
        }
    }
    while(i<n){
        cout<<a[i++]<<" ";
    }
}

int main()
{
    int arr1[] = {3, 6, 10, 12, 15,19,20}; 
    int arr2[] = {1, 3, 5, 10, 16}; 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    int m = sizeof(arr2) / sizeof(arr2[0]);
    relativeComponent(arr1,arr2,n,m);
	cout<<endl;
    return 0;
}

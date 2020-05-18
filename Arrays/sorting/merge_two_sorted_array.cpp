#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

void merge_two_sorted_array(int *a, int *b, int m, int n){
    for(int i=n-1;i>=0;i--){
        int j,last=a[m-1];
        for(j=m-2;j>=0 && a[j]>b[i];j--){
            a[j+1]=a[j];
        }
        if(j!=m-2 || last>b[i]){
            a[j+1]=b[i];
            b[i]=last;
        }
    }
}

int main()
{
    int ar1[] = {1, 5, 9, 10, 15, 20}; 
    int ar2[] = {2, 3, 8, 13}; 
    int m = sizeof(ar1)/sizeof(ar1[0]); 
    int n = sizeof(ar2)/sizeof(ar2[0]);
    merge_two_sorted_array(ar1,ar2,m,n);
    cout << "After Merging \nFirst Array: "; 
    for (int i=0; i<m; i++) 
        cout << ar1[i] << " "; 
    cout << "\nSecond Array: "; 
    for (int i=0; i<n; i++) 
        cout << ar2[i] << " ";
	cout<<endl;
    return 0;
}

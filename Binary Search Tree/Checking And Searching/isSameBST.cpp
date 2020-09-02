#include <iostream>

using namespace std;

bool isSameBSTUtil(int a[], int b[],  
                int n, int i1, int i2, 
                    int min, int max)  
{
    int j,k;

    for (j = i1; j < n; j++)  
        if (a[j] > min && a[j] < max)  
            break;  
    for (k = i2; k < n; k++)  
        if (b[k] > min && b[k] < max)  
            break;

    if (j==n && k==n)  
    return true;

    if (((j==n)^(k==n)) || a[j]!=b[k])  
    return false; 

    return isSameBSTUtil(a, b, n, j+1, k+1, a[j], max) &&
        isSameBSTUtil(a, b, n, j+1, k+1, min, a[j]);

}

bool isSameBST(int a[], int b[], int n)  
{  
    return isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX);  
} 

int main(){
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};  
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};  
    int n=sizeof(a)/sizeof(a[0]);  
    if(isSameBST(a, b, n)) 
    { 
        cout << "BSTs are same"; 
    } 
    else
    { 
        cout << "BSTs not same"; 
    } 
    cout<<endl;
    return 0;
}
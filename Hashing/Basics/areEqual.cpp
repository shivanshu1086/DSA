#include <iostream>

using namespace std;

bool areEqual(int *a, int *b, int n, int m){
    if (n != m) 
        return false;
    
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr1[] = { 3, 5, 2, 5, 2 }; 
    int arr2[] = { 2, 3, 5, 5, 2 }; 
    int n = sizeof(arr1) / sizeof(int); 
    int m = sizeof(arr2) / sizeof(int); 
  
    if (areEqual(arr1, arr2, n, m)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    cout<<endl;
    return 0;
}
#include <iostream>

using namespace std;

bool isHeap(int *a, int n){
    for(int i=0;i<=(n-1)/2;i++){
        if (a[2*i +1] > a[i]) 
            return false;
        
        if((2*i+2)<n && a[2*i+2]>a[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3}; 
    int n = sizeof(arr) / sizeof(int)-1; 
  
    isHeap(arr, n)? printf("Yes"): printf("No");
    cout<<endl;
    return 0;
}
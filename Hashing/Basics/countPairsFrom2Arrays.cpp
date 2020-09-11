#include <iostream>

using namespace std;

int countPairs(int *a, int *b, int m, int n, int x){
    int count=0;
    int l=0;
    int r=n-1;

    while(l<m && r>=0){
        if((a[l] + b[r]) == x){
            l++;
            r--;
            count++;
        }
        else if((a[l] + b[r]) < x){
            l++;
        }
        else{
            r--;
        }
    }
    return count;
}


int main(){
    int arr1[] = {1, 3, 5, 7}; 
    int arr2[] = {2, 3, 5, 8}; 
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
    int x = 10; 
    cout << "Count = "
          << countPairs(arr1, arr2, m, n, x);
    cout<<endl;
    return 0;
}
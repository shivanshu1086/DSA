#include <iostream>

using namespace std;

int find_difference(int arr[], int n, int m) 
{ 
    int max = 0, min = 0; 
  
    // sort array 
    sort(arr, arr + n); 
  
    for (int i = 0, j = n - 1; 
         i < m; i++, j--) { 
        min += arr[i]; 
        max += arr[j]; 
    } 
  
    return (max - min); 
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m = 4; 
    cout << find_difference(arr, n, m); 
    cout<<endl;
    return 0;
}
#include <iostream>
#include <numeric>
using namespace std;

int sumBetweenTwoKth(int arr[], int n, int k1, int k2) 
{
    return accumulate(arr + k1, arr + k2 - 1, 0);
}

int main(){
    int arr[] = { 20, 8, 22, 4, 12, 10, 14 }; 
    int k1 = 3, k2 = 6; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << sumBetweenTwoKth(arr, n, k1, k2); 
    cout<<endl;
    return 0;
}
#include <iostream>

using namespace std;

int countNum(int *a, int n){
    int maxi = *max_element(a,a+n);
    int mini = *min_element(a,a+n);

    return (maxi-mini+1)-n;
}

int main() {
    int arr[] = {4, 5, 3, 8, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << countNum(arr, n) << endl;
    cout<<endl;
	return 0;
}
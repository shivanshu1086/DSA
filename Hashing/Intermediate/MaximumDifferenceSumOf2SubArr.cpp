#include <iostream>
#include <unordered_map>
using namespace std;

int maxDiff(int arr[], int n) 
{
    unordered_map<int, int> hashPositive; 
    unordered_map<int, int> hashNegative;

    int SubsetSum_1 = 0, SubsetSum_2 = 0;

    for (int i = 0; i <= n - 1; i++) 
        if (arr[i] > 0) 
            hashPositive[arr[i]]++;

    for (int i = 0; i <= n - 1; i++) 
        if (arr[i] > 0 && hashPositive[arr[i]] == 1) 
            SubsetSum_1 += arr[i];

    for (int i = 0; i <= n - 1; i++) 
        if (arr[i] < 0) 
            hashNegative[abs(arr[i])]++;

    for (int i = 0; i <= n - 1; i++) 
        if (arr[i] < 0 &&  
            hashNegative[abs(arr[i])] == 1) 
            SubsetSum_2 += arr[i];

    return abs(SubsetSum_1 - SubsetSum_2);
}

int main() {
    int arr[] = { 4, 2, -3, 3, -2, -2, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum Difference = " << maxDiff(arr, n);
    cout<<endl;
	return 0;
}
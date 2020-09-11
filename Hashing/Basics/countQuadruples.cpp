#include <iostream>
#include <unordered_map>

using namespace std;

int countQuadruples(int arr1[], int arr2[], int arr3[], 
                    int arr4[], int n, int x) 
{
    int count = 0;
    unordered_map<int, int> um;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            um[arr1[i] + arr2[j]]++;
    
    for (int k = 0; k < n; k++) 
        for (int l = 0; l < n; l++) { 
            int p_sum = arr3[k] + arr4[l]; 
  
            // if 'x-p_sum' is present in 'um' then 
            // add frequency of 'x-p_sum' to 'count' 
            if (um.find(x - p_sum) != um.end()) 
                count += um[x - p_sum];
        }
    return count;
}

int main(){
    int arr1[] = { 1, 4, 5, 6 }; 
    int arr2[] = { 2, 3, 7, 8 }; 
    int arr3[] = { 1, 4, 6, 10 }; 
    int arr4[] = { 2, 4, 7, 8 }; 
  
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    int x = 30; 
    cout << "Count = "
         << countQuadruples(arr1, arr2, arr3, arr4, n, x);
    cout<<endl;
    return 0;
}
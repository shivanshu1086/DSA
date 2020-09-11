#include<iostream>
#include <unordered_map>

using namespace std;

int printKDistinct(int *arr, int n, int k){
    unordered_map<int, int> h; 
    for (int i = 0; i < n; i++) 
        h[arr[i]]++;

    if (h.size() < k) 
        return -1;
    
    int dist_count = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (h[arr[i]] == 1) 
            dist_count++; 
        if (dist_count == k) 
            return arr[i]; 
    }

    return -1;
}


int main() {
    int ar[] = {1, 2, 1, 3, 4, 2}; 
    int n = sizeof(ar) / sizeof(ar[0]); 
    cout << printKDistinct(ar, n, 2);
    cout<<endl;
	return 0;
}
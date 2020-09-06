#include <iostream>

using namespace std;


void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
}

void heapify(int arr[], int n, int i) 
{ 
    int smallest = i; // Initialize smalles as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    // If smallest is not root 
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, smallest); 
    } 
} 

void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    }
}

int main(){
    int arr[] = { 4, 6, 3, 2, 9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
    cout<<endl;
    return 0;
}
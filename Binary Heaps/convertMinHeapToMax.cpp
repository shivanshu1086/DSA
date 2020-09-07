#include <iostream>

using namespace std;

void heapify(int *a, int n, int i){
    int parent = i;
    int lchild = 2*i+1;
    int rchild = 2*i+2;

    if(lchild<n && a[lchild]>a[parent]){
        parent = lchild;
    }

    if(rchild<n && a[rchild]>a[parent]){
        parent = rchild;
    }

    if(i!=parent){
        swap(a[parent],a[i]);
        heapify(a,n,parent);
    }
}

void convertMaxHeap(int *a, int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(a,n,i);
    }
}


void printArray(int* arr, int size) 
{ 
    for (int i = 0; i < size; ++i) 
        printf("%d ", arr[i]); 
} 

int main(){
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Min Heap array : "); 
    printArray(arr, n); 
  
    convertMaxHeap(arr, n); 
  
    printf("\nMax Heap array : "); 
    printArray(arr, n);
    cout<<endl;
    return 0;
}
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

void heapSort(int *a, int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void printArray(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
   int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n);

    heapSort(arr,n);

    cout << "\nSorted array is \n"; 
    printArray(arr, n);
    cout<<endl;
    return 0;
}
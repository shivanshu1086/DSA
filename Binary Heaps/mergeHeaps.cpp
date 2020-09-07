#include <iostream>


using namespace std;

void maxHeapify(int *a, int n, int i){ 
    int parent = i;
    int lchild = 2*i+1;
    int rchild = 2*i+2;

    if(lchild<n && a[lchild]>a[parent]){
        parent=lchild;
    }

    if(rchild<n && a[rchild]>a[parent]){
        parent = rchild;
    }

    if(i!=parent){
        swap(a[i],a[parent]);
        maxHeapify(a,n,parent);
    }
}

void buildMaxHeap(int arr[], int n) 
{ 

    for (int i = n / 2 - 1; i >= 0; i--) 
        maxHeapify(arr, n, i); 
}

void mergeHeaps(int merged[], int a[], int b[], 
                int n, int m) 
{
    for (int i = 0; i < n; i++) 
        merged[i] = a[i]; 

    for (int i = 0; i < m; i++) 
        merged[n + i] = b[i];

    buildMaxHeap(merged, n + m);
}

int main(){
    int a[] = { 10, 5, 6, 2 }; 
    int b[] = { 12, 7, 9 }; 
  
    int n = sizeof(a) / sizeof(a[0]); 
    int m = sizeof(b) / sizeof(b[0]);

    int merged[m+n];
    mergeHeaps(merged, a, b, n, m);

    for (int i = 0; i < n + m; i++) 
        cout << merged[i] << " ";
    cout<<endl;
    return 0;
}
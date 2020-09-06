#include <iostream>
#include<climits>

using namespace std;

class MinHeap{
    int *harr;
    int capacity;
    int heapSize;
public:
    MinHeap(int capacity);
    void insertKey(int k);
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void MinHeapify(int );
    int popMin();
    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (2*i + 1);
    }

    int right(int i){
        return (2*i + 2);
    }

    int top(){
        return harr[0];
    }

    int getMin(){
        if(heapSize>=0)
        return harr[0];
        return INT_MAX;
    }
};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap::MinHeap(int capacity){
    harr = new int[capacity];
    this->capacity=capacity;
    this->heapSize=0;
}

void MinHeap::insertKey(int data){
    if (heapSize == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    }
    int i = heapSize;
    harr[heapSize++] = data;
    
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int pos, int new_val){
    harr[pos]=new_val;

    while(pos!=0 && harr[parent(pos)]>harr[pos]){
        swap(&harr[pos], &harr[parent(pos)]);
        pos = parent(pos);
    }
}

int MinHeap::popMin(){
    if(heapSize<=0){
        return INT_MAX;
    }

    if(heapSize==1){
        heapSize--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heapSize-1];
    heapSize--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    popMin();
}

void MinHeap::MinHeapify(int i){
    int l = left(i); 
    int r = right(i);

    int smallest = i;

    if(l<heapSize && harr[l]<harr[i]){
        smallest = l;
    }
    if(r<heapSize && harr[r]<harr[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int main(){
    MinHeap minh(11);

    minh.insertKey(3);
    minh.insertKey(2);
    minh.deleteKey(1);
    minh.insertKey(15);
    minh.insertKey(5);
    minh.insertKey(4);
    minh.insertKey(45);

    cout<<minh.popMin()<<" ";
    cout<<minh.getMin()<<" ";
    minh.decreaseKey(2,1);
    cout<<minh.getMin();
    cout<<endl;
    return 0;
}
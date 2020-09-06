#include <iostream>
#include <vector>
using namespace std;

class Minheap{
    vector<int> vec;
public:
    Minheap();
    void push(int x);
    void pop();
    void heapify(int i);
    bool isEmpty(){
        return vec.size()==1;
    }
    int topEle(){
        if(vec.size()>=1){
            return vec[1];
        }
        else{
            cout<<"Heap is empty. Insert first";
            return -1;
        }
    }
    void print(Minheap h);
};

Minheap::Minheap(){
    vec.push_back(-1);
}

void Minheap::push(int data){
    vec.push_back(data);

    int child = vec.size()-1;
    int parent = child/2;

    while(child>1 && vec[parent]>vec[child]){
        swap(vec[parent],vec[child]);
        child=parent;
        parent=child/2;
    }
}

void Minheap::pop(){
    swap(vec[vec.size()-1],vec[1]);
    vec.pop_back();

    heapify(1);
}

void Minheap::heapify(int i){
    int parent = i;
    int lchild = 2*i;
    int rchild = 2*i+1;

    if(lchild<vec.size() && vec[lchild]<vec[parent]){
        parent = lchild;
    }
    if(rchild<vec.size() && vec[rchild]<vec[parent]){
        parent = rchild;
    }

    if(i!=parent){
        swap(vec[parent],vec[i]);
        heapify(parent);
    }
}

void Minheap::print(Minheap h){
    while(!h.isEmpty()){
        cout<<h.topEle()<<" ";
        h.pop();
    }
}

int main(){
    Minheap h;
    for(int i=0;i<10;i++){
        h.push(rand()%99);
    }
    h.print(h);
    cout<<endl;
    return 0;
}
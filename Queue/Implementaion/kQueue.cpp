#include <iostream>
#include <queue>

using namespace std;

class kQueue{
    int a[10];
    int front[3];
    int next[3];
    int rear[10];
    int n,k,free;
public:
    kQueue(int k, int n){
        this->n=n;
        this->k=k;
        // a = new int[n];
        // front = new int[k];
        // rear = new int[k];
        // next = new int[n];

        for(int i=0;i<k;i++){
            front[i]=-1;
        }

        free=0;
        for(int i=0;i<n-1;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
    }

    bool isFull(){
        return free==-1;
    }

    bool isEmpty(int qn){
        return (front[qn]==-1);
    }

    void enqueue(int x, int qn){
        if(isFull()){
            cout<<"This queue is full please try another one!"<<endl;
            return;
        }

        int i=free;
        free=next[i];

        if(isEmpty(qn)){
            front[qn]=i;
        }
        else{
            next[rear[qn]]=i;
        }

        next[i]=-1;
        rear[qn]=i;
        a[i]=x;
    }

    int dequeue(int qn){
        if(isEmpty(qn)){
            cout<<"This queue is empty try another one!"<<endl;
            return INT_MIN;
        }

        int i=front[qn];
        front[qn] = next[i];
        next[i]=free;
        free = i;

        return a[i];
    }

};

int main(){
    kQueue Queue(3,10);
    Queue.enqueue(15, 2); 
    Queue.enqueue(45, 2); 
  
    Queue.enqueue(17, 1); 
    Queue.enqueue(49, 1); 
    Queue.enqueue(39, 1); 
  
    Queue.enqueue(11, 0); 
    Queue.enqueue(9, 0); 
    Queue.enqueue(7, 0); 
  
    cout << "Dequeued element from queue 2 is " << Queue.dequeue(2) << endl; 
    cout << "Dequeued element from queue 1 is " << Queue.dequeue(1) << endl; 
    cout << "Dequeued element from queue 0 is " << Queue.dequeue(0) << endl; 
    cout<<endl;
	return 0;
}
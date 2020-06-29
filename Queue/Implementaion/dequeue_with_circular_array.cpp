#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

class Deque{
    int a[MAX];
    int front;
    int rear;
    int size;
public:
    Deque(int size){
        this->size=size;
        front=-1;
        rear=0;
    }
    bool isFull(){
        return ((front==0 && rear==size-1) || (front==rear+1));
    }
    bool isEmpty(){
        return (front==-1);
    }
    void insertrear(int x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }

        if(front==-1){
            front=0;
        }
        else if(rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        a[rear]=x;
    }

    int getRear(){
        return a[rear];
    }

    int getFront(){
        return a[front];
    }

    void deleterear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        if(rear==front){
            front=-1;
            rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
    }

    void insertfront(int x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }

        if(front==-1){
            front=0;
            rear=0;
        }
        else if(front==0){
            front=size-1;
        }
        else{
            front--;
        }
        a[front]=x;
    }

    void deletefront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            if(front==size-1){
                front=0;
            }
            else{
                front++;
            }
        }
    }
};


int main(){
    Deque dq(5); 
    cout << "Insert element at rear end  : 5 \n"; 
    dq.insertrear(5); 
  
    cout << "insert element at rear end : 10 \n"; 
    dq.insertrear(10); 
  
    cout << "get rear element " << " "
         << dq.getRear() << endl; 
  
    dq.deleterear(); 
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl; 
  
    cout << "inserting element at front end \n"; 
    dq.insertfront(15); 
  
    cout << "get front element " << " "
         << dq.getFront() << endl; 
  
    dq.deletefront(); 
  
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl; 
    cout<<endl;
	return 0;
}
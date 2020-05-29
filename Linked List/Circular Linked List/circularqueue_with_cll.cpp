#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

class queue{
public:
    node *front;
    node *rear;

    queue(){
        front=NULL;
        rear=NULL;
    }

    void enqueue(int x){
        if(front==NULL){
            front= new node(x);
            rear=front;
        }
        else{
            node *temp=new node(x);
            rear->next=temp;
            rear=temp;
            rear->next=front;
        }
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue is empty!";
            return;
        }
        node *freenode=front;
        node *temp=front->next;
        node *traverse=front;
        while(traverse->next!=front){
            traverse=traverse->next;
        }
        traverse->next=temp;
        front=temp;
        delete freenode;
    }

    int frontodqueue(){
        return front->data;
    }

    int rearofqueue(){
        return rear->data;
    }
};

int main(){
    queue q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(10);
    cout<<q.frontodqueue()<<endl;
    cout<<q.rearofqueue()<<endl;
    q.dequeue();
    cout<<q.frontodqueue()<<endl;
    cout<<endl;
    return 0;
}
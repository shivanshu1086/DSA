#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

class qNode{
public:
    int data;
    qNode *next;
    qNode(int x){
        data=x;
        next=NULL;
    }
};

class Queue{
public:
    qNode *front;
    qNode *rear;

    Queue(){
        front=rear=NULL;
    }

    void enqueue(int x){
        qNode *temp=new qNode(x);
        if(rear==NULL){
            front=rear=temp;
            return;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }

    void dequeue(){
        if(front==NULL){
            return;
        }
        qNode *temp = front;
        front = front->next;

        if(front==NULL){
            rear=NULL;
        }

        delete(temp);
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout<<"Front :"<<q.front->data<<endl;
    cout<<"Rear :"<<q.rear->data<<endl;
    cout<<endl;
	return 0;
}
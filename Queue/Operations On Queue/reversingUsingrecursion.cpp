#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<long long int> &Queue){
    if(Queue.empty()){
        return;
    }

    long long int data=Queue.front();
    Queue.pop();

    reverseQueue(Queue);

    Queue.push(data);
}

int main(){
    queue<long long int> Queue; 
    Queue.push(56); 
    Queue.push(27); 
    Queue.push(30); 
    Queue.push(45); 
    Queue.push(85); 
    Queue.push(92); 
    Queue.push(58); 
    Queue.push(80); 
    Queue.push(90); 
    Queue.push(100); 
    reverseQueue(Queue);

    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
    cout<<endl;
	return 0;
}
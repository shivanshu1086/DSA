#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

void reverseQueueFirstKElements(int k, queue<int> &Queue){
    stack<int> s;
    int cnt=0;
    while(cnt<k){
        s.push(Queue.front());
        Queue.pop();
        cnt++;
    }
    int n=Queue.size();
    cnt=0;
    
    while(!s.empty()){
        Queue.push(s.top());
        s.pop();
    }

    while(cnt<n){
        int f=Queue.front();
        Queue.pop();
        Queue.push(f);
        cnt++;
    }
}

void Print(queue<int> &Queue){
    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
}

int main() {
    queue<int> Queue; 
    Queue.push(10); 
    Queue.push(20); 
    Queue.push(30); 
    Queue.push(40); 
    Queue.push(50); 
    Queue.push(60); 
    Queue.push(70); 
    Queue.push(80); 
    Queue.push(90); 
    Queue.push(100);

    int k = 5; 
    reverseQueueFirstKElements(k, Queue);
    Print(Queue);
    cout<<endl;
	return 0;
}
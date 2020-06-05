#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;

    node(int x){
        data=x;
        next=NULL;
    }
};

class Linkedlist{
public:
    node *head;
    node *tail;

    Linkedlist(){
        head=NULL;
        tail=NULL;
    }

    void insertionAtEnd(int x){
        if(head==NULL){
            head = new node(x);
            tail=head;
        }

        else{
            node *temp=new node(x);
            tail->next=temp;
            tail=temp;
        }
    }

    int print(){
        int i=0;
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
            i++;
        }
        return i;
    }

    void print_reverse(int n){
        int j=0;
        node *curr=head;
        while(curr!=NULL){
            for(int i=0;i<2*(n-j);i++){
                printf(" ");
            }
            printf("%d\r",curr->data);
            curr=curr->next;
            j++;
        }
    }
};

int main(){
    Linkedlist l;
    l.insertionAtEnd(1);
    l.insertionAtEnd(2);
    l.insertionAtEnd(3);
    l.insertionAtEnd(4);
    l.insertionAtEnd(5);
    int i=l.print();
    cout<<endl;
    l.print_reverse(i);
    cout<<endl;
    return 0;
}
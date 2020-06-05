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
};


bool is_find(node *head1, node *head2){
    if(head1==NULL || head2==NULL){
        return false;
    }

    if(head1==NULL && head2==NULL){
        return true;
    }

    node *temp1=head1;
    node *temp2=head2;

    while(head2!=NULL){
        temp2=head2;
        while(temp1!=NULL){
            if(temp2==NULL) return false;
            else if(temp1->data==temp2->data){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else{
                break;
            }
        }
        if(temp1==NULL){
            return true;
        }

        temp1=head1;
        head2=head2->next;
    }
    return false;
}

int main(){
    Linkedlist l;
    l.insertionAtEnd(1);
    l.insertionAtEnd(2);
    l.insertionAtEnd(3);
    l.insertionAtEnd(4);

    Linkedlist l2;
    l2.insertionAtEnd(1);
    l2.insertionAtEnd(2);
    l2.insertionAtEnd(1);
    l2.insertionAtEnd(2);
    l2.insertionAtEnd(3);
    l2.insertionAtEnd(4);

    is_find(l.head,l2.head)? cout<<"List Found":cout<<"List not found";
    cout<<endl;
    return 0;
}
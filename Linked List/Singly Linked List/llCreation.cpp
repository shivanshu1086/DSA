#include <iostream>

using namespace std;

//class for node
class node{
public:
    int data;
    node *next;

    //constructor
    node(int x){
        data=x;
        next=NULL;
    }
};

//class for linked list
class linkedlist{
public:
    node *head;
    node *tail;

    //constructor
    linkedlist(){
        head=NULL;
        tail=NULL;
    }

//functions on ll

//insertion

    void insertAtFront(int x){//insertion from front
        if(head==NULL){
            head = new node(x);
            tail = head;
        }
        else{
            node *temp=new node(x);
            temp->next=head;
            head=temp;
        }
    }

    void insertAtEnd(int x){//insertion at the end
        if(head==NULL){
            head=new node(x);
            tail=head;
        }
        else{
            node *temp=new node(x);
            tail->next =temp;
            tail=temp;
        }
    }

    void insertAtMid(int x, int pos){//insertion at the mid or any pos
        if(pos==0){
            insertAtFront(x);
        }
        else if(pos>length()){
            insertAtEnd(x);
        }
        else{
            node *move=head;
            int i=1;
            while(i<pos-1){
                move=move->next;
                i++;
            }
            node *temp=new node(x);
            temp->next=move->next;
            move->next=temp;
        }
    }
//------------------insertion ends----------------------------------//

//deletion

    void deleteFromStart(){//deletion from the starting node
        if(length()==1){
            head=NULL;
            tail=NULL;
        }
        if(head==NULL){
            return;
        }
        else{
            node *temp=head;
            head=head->next;
            delete temp;
        }
    }

    void deleteFromEnd(){//delete from the end of node
        if(length()==1){
            head=NULL;
            tail=NULL;
        }
        if(head==NULL){
            return;
        }
        else{
            node *temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            temp->next=NULL;
            tail=temp;
        }
    }

    void deleteFromMid(int pos){//delete from ant position
        if(pos==0){
            deleteFromStart();
        }
        if(pos>length()){
            deleteFromEnd();
        }
        else{
            int no=1;
            node *move=head;
            while(no<pos-1){
                move=move->next;
                no++;
            }
            node *temp=move->next;
            move->next=temp->next;
            delete temp;
        }
    }

//------------------deletion ends----------------------------------//

    bool findele(int x){//find the element in the linked list
        return findeleInLL(head,x);
    }

//------------useful funtions-------------------------------------//
    //printing function
    void print(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    //length of the linked list
    int length(){
        node *temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    bool findeleInLL(node *head, int x){
        if(head==NULL){
            return false;
        }
        else if(head->data==x){
            return true;
        }
        else{
            return findeleInLL(head->next,x);
        }
    }
//------------------------ends------------------------------------//

//---------------------mergesort in linkedlist-------------------//

    node *mergesort(node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }//base condition
        node *mid=findmid(head);//stores the mid point

        node *a=head;
        node *b=mid->next;//divides the ll into two halves

        //stores null at the end of the first part
        mid->next=NULL;

        a=mergesort(a);
        b=mergesort(b);//further partition

        //mergeing the ll
        node *newHead = mergell(a,b);
        return newHead;
    }

    //finds mid point
    node *findmid(node *head){
        node *fastptr=head->next;
        node *slowptr=head;
        while(fastptr!=NULL && fastptr->next!=NULL){
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
        }
        return slowptr;
    }

    //merge the ll parts
    node *mergell(node *a, node *b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        //take a node to store the merged ll
        node *c;
        if(a->data>b->data){
            c=b;//ll starts with b
            c->next=mergell(a,b->next);
        }
        else{
            c=a;
            c->next=mergell(a->next,b);
        }
        return c;
    }
//---------merge sort ends--------------------------------//
};


int main()
{
    linkedlist l;
    for(int i=1;i<10;i++){
        l.insertAtFront(i);
    }
    // l.print();
    // cout<<endl;
    // l.insertAtMid(10,3);
    // l.deleteFromStart();
    // l.deleteFromStart();
    // l.deleteFromStart();
    // l.deleteFromEnd();
    // l.deleteFromEnd();
    // l.deleteFromMid(3);
    // l.deleteFromMid(3);
    // l.head=l.mergesort(l.head);
    l.print();
    cout<<endl<<boolalpha<<l.findele(5);
	cout<<endl;
    return 0;
}

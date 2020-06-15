#include <iostream>
#include <stack>

using namespace std;

class Stack{
public:
    int data;
    Stack *next;
};

Stack *createStack(){
    Stack *s=new Stack();
    s=NULL;
    return s;
}

bool isEmpty(Stack *s){
    return (s==NULL);
}

int pop(Stack **s)  
{  
    int x;  
    Stack *temp;  
  
    x = (*s)->data;  
    temp = *s;  
    (*s) = (*s)->next;  
    free(temp);  
    return x;  
} 

int top(Stack *s){
    return s->data;
}

void push(Stack **s, int data){
    Stack *p = new Stack();
    p->data=data;
    p->next=*s;
    *s=p;
}

void print(Stack **s){
    Stack *p=*s;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void sortedAdd(Stack **s, int data){
    Stack *z=*s;

    Stack *q=new Stack();
    Stack *r=new Stack();
    q->data=data;

    while(z!=NULL && z->data>data){
        r=z;
        z=z->next;
    }

    r->next=q;
    q->next=z;
}

void sortedInsertion(Stack **s, int x){
    if(isEmpty(*s) or x>top(*s)){
        push(&(*s),x);
        return;
    }

    int temp = pop(s);
    sortedInsertion(s,x);
    push(&(*s),temp);
}

void sort(Stack **s){
    if(!isEmpty(*s)){
        int x=pop(s);
        sort(s);
        sortedInsertion(s,x);
    }
}

int main(){
    Stack *s=createStack();
    push(&s,30);
    push(&s,-5);
    push(&s,18);
    push(&s,14);
    push(&s,-3);
    print(&s);

    cout<<endl;
    sort(&s);
    print(&s);
    cout<<endl;
	return 0; 
}
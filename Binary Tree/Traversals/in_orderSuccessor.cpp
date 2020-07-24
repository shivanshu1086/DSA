#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    node *next;
};

node *newNode(int x){
    node *tmp = new node();
    tmp->data = x;
    tmp->left=tmp->right=NULL;
    tmp->next=NULL;
    return tmp;
}

void populateNext(node *p){
    static node *next = NULL;
    if(p){
        populateNext(p->right);
        p->next=next;
        next=p;
        populateNext(p->left);
    }
}

int main(){
    node *root = newNode(10);  
    root->left = newNode(8);  
    root->right = newNode(12);  
    root->left->left = newNode(3);
    populateNext(root);
    node *ptr = root->left->left;  
    while(ptr){
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)  
             << endl;  
        ptr = ptr->next;  
    }
	cout<<endl;
    return 0;
}

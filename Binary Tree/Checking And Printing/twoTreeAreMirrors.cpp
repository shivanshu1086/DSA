#include <iostream>
#include <unordered_set>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp = new node();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

int areMirror(node *a, node *b){
    if(a==NULL && b==NULL){
        return true;
    }

    if(a==NULL || b==NULL){
        return false;
    }

    return a->data==b->data && areMirror(a->left,b->right) && areMirror(a->right,b->left);
}


int main(){
    node *a = newNode(1);
    node *b = newNode(1);
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5);

    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4);

    areMirror(a, b)? cout << "Yes" : cout << "No";
    cout<<endl;
    return 0;
}
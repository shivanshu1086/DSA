#include <iostream>
#include <stack>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp = new node();
    tmp->data = x;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void in_order_without_recur(node *root){
    stack<node *> s;
    node *curr = root;

    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

int main(){
    node *root = newNode(1);
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5);
    in_order_without_recur(root);
	cout<<endl;
    return 0;
}

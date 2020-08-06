#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
};

node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}

void reverseLevelOrder(node *root){
    stack<node *> s;
    queue<node *> q;
    q.push(root);

    while(!q.empty()){
        root = q.front();
        q.pop();
        s.push(root);

        if(root->right){
            q.push(root->right);
        }

        if(root->left){
            q.push(root->left);
        }
    }

    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main(){
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    reverseLevelOrder(root);
    cout<<endl;
    return 0;
}
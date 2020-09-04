#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data){
    if(root==NULL){
        return newNode(data);
    }

    if(root->data>data){
        root->left =  insert(root->left,data);
    }
    else{
        root->right =  insert(root->right,data);
    }
    return root;
}


int Ceil(Node* root, int input) 
{
    if(root==NULL){
        return -1;
    }

    if(root->data == input){
        return root->data;
    }

    if(root->data<input){
        return Ceil(root->right,input);
    }

    int ceil = Ceil(root->left,input);
    return (ceil>=input)?ceil:root->data;
}


int main(){
    Node* root = newNode(8); 
  
    root->left = newNode(4); 
    root->right = newNode(12); 
  
    root->left->left = newNode(2); 
    root->left->right = newNode(6); 
  
    root->right->left = newNode(10); 
    root->right->right = newNode(14); 
  
    for (int i = 0; i < 16; i++) 
        cout << i << " " << Ceil(root, i) << endl;
    cout<<endl;
    return 0;
}
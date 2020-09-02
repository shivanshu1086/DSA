#include <iostream>
#include <set>

using namespace std;

class Node  
{  
    public: 
    int data;  
    Node *left;  
    Node *right;  
};  

Node * newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}  

void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    
    printInorder(root->left);
    cout << root->data << " "; 
    printInorder(root->right); 
}

void storeinorderInSet(Node *root, set<int> &s){
    if(root== NULL){
        return;
    }

    else{
        storeinorderInSet(root->left,s);
        s.insert(root->data);
        storeinorderInSet(root->right,s);
    }
}

void setToBST(set<int> &s, Node *root){
    if(root==NULL){
        return;
    }

    setToBST(s,root->left);
    auto it= s.begin();
    root->data = *it;
    s.erase(it);
    setToBST(s,root->right);
}

void binaryTreeToBST(Node *root){
    set<int> s;

    storeinorderInSet(root, s);

    setToBST(s, root);
}

int main(){
    Node* root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11);

    binaryTreeToBST(root); 
    cout << "Inorder traversal of BST is: " << endl;
    printInorder(root);
    cout<<endl;
    return 0;
}
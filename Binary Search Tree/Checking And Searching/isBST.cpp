#include <iostream>

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

bool isBSTUtil(Node *root, Node *prev){
    if(root){
        if(!isBSTUtil(root->left,prev)){
            return false;
        }
        if(prev!=NULL && root->data<=prev->data){
            return false;
        }
        prev=root;
        return isBSTUtil(root->right,prev);
    }
    return true;
}


bool isBST(Node *root){
    Node *prev=NULL;
    return isBSTUtil(root,prev);
}

int main(){
    struct Node *root = newNode(3); 
    root->left     = newNode(2); 
    root->right     = newNode(5); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
  
    if (isBST(root)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST";
    cout<<endl;
    return 0;
}
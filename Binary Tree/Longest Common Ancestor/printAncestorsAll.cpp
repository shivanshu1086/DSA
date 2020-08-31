#include <iostream>

using namespace std;

struct Node 
{ 
    struct Node *left, *right; 
    int key; 
}; 
  
// Utility function to create a new tree Node 
Node* newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct Node* findLCA(struct Node* root, int n1, int n2) 
{
    if(root==NULL){
        return NULL;
    }

    if(root->key==n1 || root->key==n2){
        return root;
    }

    Node *left = findLCA(root->left,n1,n2);
    Node *right = findLCA(root->right,n1,n2);

    if(left && right){
        return root;
    }

    return (left)?left:right;
}

bool printAncestors(Node *root, int k){
    if(root==NULL){
        return false;
    }

    if(root->key==k){
        cout<<root->key<<" ";
        return true;
    }

    if(printAncestors(root->left,k) || printAncestors(root->right,k)){
        cout<<root->key<<" ";
        return true;
    }

    return false;
}

bool findCommonNodes(struct Node* root, int first, 
                                       int second) 
{
    struct Node* LCA = findLCA(root, first, second);


    if(LCA==NULL){
        return false;
    }

    printAncestors(root,LCA->key);
    return true;
}


int main(){
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->right->left->left = newNode(9); 
    root->right->left->right = newNode(10); 
  
    if (findCommonNodes(root, 9, 7) == false) 
        cout << "No Common nodes"; 
    cout<<endl;
    return 0;
}
#include <iostream>
#include <queue>

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

void printPreorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    
    printPreorder(root->left);
    cout << root->data << " "; 
    printPreorder(root->right); 
}

void reversePath(Node **root, int &key, queue<int> &q1){
    if(root==NULL){
        return;
    }
    if((*root)->data==key){
        q1.push((*root)->data);
        (*root)->data = q1.front();
        q1.pop();
        return;
    }
    else if((*root)->data>key){
        q1.push((*root)->data);

        reversePath(&(*root)->left,key,q1);

        (*root)->data = q1.front();
        q1.pop();
    }
    else{
        q1.push((*root)->data);

        reversePath(&(*root)->right,key,q1);

        (*root)->data = q1.front();

        q1.pop();
    }
    return;
}


int main(){
    struct Node* root = NULL;
    queue<int> q1;
    int k = 80;
    root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);

    root->left->left = newNode(20);
    root->left->right = newNode(40);

    root->right->left = newNode(60);
    root->right->right = newNode(80);

    cout << "Before Reverse :" << endl;
    printPreorder(root);
    cout << "\n";

    reversePath(&root, k, q1);

    cout << "After Reverse :" << endl;
    printPreorder(root);

    cout<<endl;
    return 0;
}
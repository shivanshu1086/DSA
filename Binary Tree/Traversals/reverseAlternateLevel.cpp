#include <iostream>
#define MAX 100
using namespace std;

struct Node 
{ 
    char data; 
    struct Node* left; 
    struct Node* right; 
};

Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}

void preorder(struct Node *root1, struct Node* root2, int lvl){
    if(root1==NULL || root2==NULL){
        return;
    }

    if(lvl%2==0){
        swap(root1->data,root2->data);
    }

    preorder(root1->left,root2->right,lvl+1);
    preorder(root1->right,root2->left,lvl+1);
}

void reverseAlternate(Node *root){
    preorder(root->left, root->right, 0);
}

void printInorder(struct Node *root) 
{ 
    if (root == NULL) 
       return; 
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
}

int main(){
    struct Node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o');

    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root);
    reverseAlternate(root);
    cout<<endl;
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root);
    cout<<endl;
    return 0;
}
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

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void correctBSTUtil( struct Node* root, struct Node** first, 
                     struct Node** middle, struct Node** last, 
                     struct Node** prev ){
    if(root){
        correctBSTUtil( root->left, first, middle, last, prev );

        if (*prev && root->data < (*prev)->data) 
        {
            if ( !*first ) 
            { 
                *first = *prev; 
                *middle = root; 
            }
            else{
                *last = root;
            }
        }

        *prev = root;

        correctBSTUtil( root->right, first, middle, last, prev );
    }
}

void swap( int* a, int* b ) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void correctBST( struct Node* root ) 
{
    struct Node *first, *middle, *last, *prev; 
    first = middle = last = prev = NULL;

    correctBSTUtil( root, &first, &middle, &last, &prev );

    if( first && last ) 
        swap( &(first->data), &(last->data) ); 
    else if( first && middle ) // Adjacent nodes swapped 
        swap( &(first->data), &(middle->data) );
}

int main(){
    struct Node *root = newNode(6); 
    root->left        = newNode(10); 
    root->right       = newNode(2); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(12); 
    root->right->left = newNode(7);

    printf("Inorder Traversal of the original tree \n"); 
    inorder(root); 
  
    correctBST(root); 
  
    printf("\nInorder Traversal of the fixed tree \n"); 
    inorder(root);
    cout<<endl;
    return 0;
}
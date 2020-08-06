#include <iostream>
#include <map>
using namespace std;

struct Node 
{ 
    int data; 
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

void inorder(Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
}

Node* reverseTreePathUtil(Node* root, int data, 
       map<int, int>& temp, int level, int& nextpos) 
{
    if(root==NULL){
        return NULL;
    }

    if(data==root->data){
        temp[level] = root->data;
        root->data = temp[nextpos];
        nextpos++; 
        return root;
    }

    temp[level] = root->data;
    Node *left, *right; 
    left = reverseTreePathUtil(root->left, data, temp,  
                                  level + 1, nextpos); 
    if (left == NULL) 
        right = reverseTreePathUtil(root->right, data,  
                            temp, level + 1, nextpos);

    if (left || right) { 
        root->data = temp[nextpos]; 
        nextpos++; 
        return (left ? left : right); 
    }

    return NULL;
}

void reverseTreePath(Node *root, int data){
    map<int,int> temp;

    int nextpos=0;
    reverseTreePathUtil(root, data, temp, 0, nextpos);
}

int main(){
    Node* root = newNode(7); 
    root->left = newNode(6); 
    root->right = newNode(5); 
    root->left->left = newNode(4); 
    root->left->right = newNode(3); 
    root->right->left = newNode(2); 
    root->right->right = newNode(1);
    int data = 4;
    reverseTreePath(root, data);
    inorder(root);
    cout<<endl;
    return 0;
}
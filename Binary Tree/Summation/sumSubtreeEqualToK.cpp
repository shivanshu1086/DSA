#include <iostream>
#include <queue>
using namespace std;

class Node 
{ 
public: 
    int data; 
    Node* left, *right; 
    
};

Node* newnode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

bool findLargestSubtreeSumUtil(Node* root, int *cur_sum, int sum) 
{
    if (root == NULL){
        *cur_sum=0;   
        return false;
    }

    int sum_left = 0, sum_right = 0; 
    return ( findLargestSubtreeSumUtil(root->left, &sum_left, sum) || 
             findLargestSubtreeSumUtil(root->right, &sum_right, sum) || 
        ((*cur_sum = sum_left + sum_right + root->data) == sum));
}

bool sumSubtree(Node *root, int sum){
    if(root==NULL){
        return false;
    }
    int currSum=0;
    return findLargestSubtreeSumUtil(root, &currSum, sum);
}

int main(){
    struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    int sum = 22; 
  
    if (sumSubtree(root, sum)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    cout<<endl;
    return 0;
}
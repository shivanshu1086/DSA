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

int maxDiffUtil(Node* t, int *res) 
{
    if(t==NULL){
        return INT_MAX;
    }

    if (t->left == NULL && t->right == NULL) 
        return t->key;
    
    int val = min(maxDiffUtil(t->left, res), 
                  maxDiffUtil(t->right, res));

    *res = max(*res, t->key - val);

    return min(val, t->key);
}

int maxDiff(Node *root) 
{ 
    // Initialising result with minimum int value 
    int res = INT_MIN; 
  
    maxDiffUtil(root, &res); 
  
    return res; 
}



int main(){
    Node* root; 
    root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
  
    printf("Maximum difference between a node and"
           " its ancestor is : %d\n", maxDiff(root));
    cout<<endl;
    return 0;
}
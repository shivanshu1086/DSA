#include <iostream>
#include <unordered_set>

using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
};

struct Node* newnode(int item) 
{ 
    struct Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node *insert(Node *root, int x){
    if(root==NULL){
        return newnode(x);
    }
    if(root->data>x){
        root->left = insert(root->left,x);
    }
    else if(root->data<x){
        root->right = insert(root->right,x);
    }
    return root;
}

void maxDiffUtil(struct Node *root, int k, int &min_diff, 
                                      int &min_diff_key) 
{
    if(root==NULL){
        return;
    }

    if(root->data==k){
        min_diff_key = k; 
        return;
    }

    if (min_diff > abs(root->data - k)) 
    { 
        min_diff = abs(root->data - k); 
        min_diff_key = root->data; 
    }

    if (k < root->data) 
        maxDiffUtil(root->left, k, min_diff, min_diff_key); 
    else
        maxDiffUtil(root->right, k, min_diff, min_diff_key);

}

int maxDiff(Node *root, int k) 
{
    int min_diff = INT_MAX, min_diff_key = -1;
    maxDiffUtil(root, k, min_diff, min_diff_key);
    return min_diff_key;
}


int main(){
    struct Node *root = newnode(9); 
    root->left    = newnode(4); 
    root->right   = newnode(17); 
    root->left->left = newnode(3); 
    root->left->right = newnode(6); 
    root->left->right->left = newnode(5); 
    root->left->right->right = newnode(7); 
    root->right->right = newnode(22); 
    root->right->right->left = newnode(20); 
    int k = 18; 
    cout << maxDiff(root, k);
    cout<<endl;
    return 0;
}
#include <iostream>

using namespace std;
struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

void kthLargestUtil(Node *root, int k, int &c) 
{
    if (root == NULL || c >= k) 
        return;

    kthLargestUtil(root->right, k, c);

    c++;

    if(c==k){
        cout << "K'th largest element is "
             << root->key << endl; 
        return;
    }

    kthLargestUtil(root->left, k, c);
}

void kthLargest(Node *root, int k) 
{
    int c = 0; 
  
    // Note that c is passed by reference 
    kthLargestUtil(root, k, c);
}

int main(){
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
    int c = 0; 
    for (int k=1; k<=7; k++) 
        kthLargest(root, k);
    cout<<endl;
    return 0;
}
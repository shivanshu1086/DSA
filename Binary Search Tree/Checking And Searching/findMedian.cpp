#include <iostream>

using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
};

struct Node* newNode(int item) 
{ 
    struct Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}
struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
}

int countNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}

void medianNodeUtil(Node *root, int *k, int *node){
    if(root){
        medianNodeUtil(root->left,k,node);
        if(*k==1){
            *node = root->data;
            *k = *k-1;
        }
        else{
             *k = *k-1;
        }
        medianNodeUtil(root->right,k,node);
    }
}

int medianNode(Node *root, int *k){
    int node;
    medianNodeUtil(root, k,&node);
    return node;
}

int findMedian(Node *root){
    int count = countNodes(root);
    
    if(count&1){//odd
        int k=(count+1)/2;
        return medianNode(root, &k);
    }
    else{
        int n1_k = count/2;
        int n2_k = (count/2)+1;
        int n1 = medianNode(root,&n1_k);
        int n2 = medianNode(root,&n2_k);

        return (n1+n2)/2;
    }
}

int main(){
    struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    insert(root, 90); 
  
    cout << "\nMedian of BST is "
         << findMedian(root);
    cout<<endl;
    return 0;
}
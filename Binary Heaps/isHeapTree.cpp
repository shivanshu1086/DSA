#include <iostream>

using namespace std;

struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
}; 
   
/* Helper function that allocates a new node */
struct Node *newNode(int k) 
{ 
    struct Node *node = new Node; 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
}

unsigned int countNodes(Node *root){
    if(root==NULL){
        return 0;

    }
    return (1+ countNodes(root->left) + countNodes(root->right));
}

bool isCompleteTree(Node *root, unsigned int node_count, unsigned int index){
    if(root==NULL){
        return true;
    }

    if(index>=node_count){
        return false;
    }

    return isCompleteTree(root->left,node_count,2*index+1)&&isCompleteTree(root->right,node_count,2*index+2);
}

bool isHeap(Node *root){
    if (root->left == NULL && root->right == NULL) 
        return (true);
    
    if(root->right==NULL){
        return (root->key>=root->left->key);
    }
    else{
        if (root->key >= root->left->key && 
            root->key >= root->right->key) 
            return ((isHeap(root->left)) && 
                    (isHeap(root->right))); 
        else
            return (false);
    }
}

bool isHeapWrapper(Node *root){
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
    if(isCompleteTree(root,node_count,index) && isHeap(root)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(9); 
    root->right = newNode(8); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    root->left->left->left = newNode(3); 
    root->left->left->right = newNode(2); 
    root->left->right->left = newNode(1); 
   
    if (isHeapWrapper(root)) 
        cout << "Given binary tree is a Heap\n"; 
    else
        cout << "Given binary tree is not a Heap\n";
    cout<<endl;
    return 0;
}
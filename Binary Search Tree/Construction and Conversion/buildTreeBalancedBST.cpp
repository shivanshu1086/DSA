#include <iostream>
#include <vector>

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

void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    
    printInorder(root->left);
    cout << root->data << " "; 
    printInorder(root->right); 
}

void storeBSTNodes(Node *root, vector<Node *> &n){
    if (root == NULL) return; 
    
    printInorder(root->left);
    n.push_back(root);
    printInorder(root->right); 
}

Node *buildTreeUtil(vector<Node *>nodes, int start, int end){
    if(start>end){
        return NULL;
    }

    int mid = start+end / 2;
    Node *root = nodes[mid];

    root->left  = buildTreeUtil(nodes, start, mid-1); 
    root->right = buildTreeUtil(nodes, mid+1, end);
    return root;
}

Node* buildTree(Node* root) 
{ 
    // Store nodes of given BST in sorted order 
    vector<Node *> nodes; 
    storeBSTNodes(root, nodes); 
  
    // Constucts BST from nodes[] 
    int n = nodes.size(); 
    return buildTreeUtil(nodes, 0, n-1);
}

int main(){
    Node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
  
    root = buildTree(root); 
  
    // printf("Preorder traversal of balanced "
    //         "BST is : \n"); 
    printInorder(root);
    cout<<endl;
    return 0;
}
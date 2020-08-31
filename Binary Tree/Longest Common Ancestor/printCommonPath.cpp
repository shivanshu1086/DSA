#include <iostream>
#include <stack>
using namespace std;

struct Node 
{ 
    struct Node *left, *right; 
    int key; 
}; 
  
// Utility function to create a new tree Node 
Node* getNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct Node *LCA(struct Node *root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->key==n1 || root->key==n2){
        return root;
    }

    Node *left = LCA(root->left,n1,n2);
    Node *right = LCA(root->right,n1,n2);

    if(left && right){
        return root;
    }

    return (left)?left:right;
}

bool store_ancestors(Node *root, int k, stack<Node *> &s){
    if(root==NULL){
        return false;
    }

    if(root->key==k){
        s.push(root);
        return true;
    }

    if(store_ancestors(root->left,k,s) || store_ancestors(root->right,k,s)){
        s.push(root);
        return true;
    }

    return false;
}

void printCommonPath(Node *root, int n1, int n2){
    Node *lca = LCA(root,n1,n1);

    if(lca==NULL){
        return;
    }

    stack<Node *> s;

    store_ancestors(root,lca->key,s);

    while(!s.empty()){
        cout<<s.top()->key<<"->";
        s.pop();
    }
}

int main(){
    struct Node *root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->left->right->left = getNode(8); 
    root->right->left->right = getNode(9); 
          
    int n1 = 4, n2 = 8; 
    printCommonPath(root, n1, n2); 
    cout<<endl;
    return 0;
}
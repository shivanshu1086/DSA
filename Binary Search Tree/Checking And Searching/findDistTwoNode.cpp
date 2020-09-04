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

struct Node* insert(struct Node* Node, int data) 
{ 
    /* If the tree is empty, return a new Node */
    if (Node == NULL) 
        return newNode(data); 
  
    /* Otherwise, recur down the tree */
    if (data < Node->data) 
        Node->left = insert(Node->left, data); 
    else if (data > Node->data) 
        Node->right = insert(Node->right, data); 
  
    /* return the (unchanged) Node pointer */
    return Node; 
}

Node *findLca(Node *root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data>n1 && root->data>n2){
        return findLca(root->left,n1,n2);
    }

    if(root->data<n1 && root->data<n2){
        return findLca(root->right,n1,n2);
    }

    return root;
}

int findLevel(Node *lca, int k, int level){
    if(lca==NULL){
        return 0;
    }

    if(lca->data==k){
        return level;
    }

    if(lca->data>k){
        return findLevel(lca->left,k,level+1);
    }

    return findLevel(lca->right,k,level+1);

}

int findDistWrapper(Node *root, int a, int b){
    Node *lca = findLca(root, a, b);

    int d1 = findLevel(lca,a,0);
    int d2 = findLevel(lca,b,0);
    return d1+d2;
}


int main(){
    struct Node* root = NULL; 
    root = insert(root, 20); 
    insert(root, 10); 
    insert(root, 5); 
    insert(root, 15); 
    insert(root, 30); 
    insert(root, 25); 
    insert(root, 35);
    cout << findDistWrapper(root, 25, 35);
    cout<<endl;
    return 0;
}
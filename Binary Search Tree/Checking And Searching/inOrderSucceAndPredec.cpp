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

Node *insert(Node *root, int x){
    if(root==NULL){
        return newNode(x);
    }
    if(root->data>x){
        root->left = insert(root->left,x);
    }
    else if(root->data<x){
        root->right = insert(root->right,x);
    }
    return root;
}

Node *minVal(Node *root){
    Node *curr = root;

    while(curr->left!=NULL){
        curr = curr->left;
    }

    return curr;
}

Node *inOrderSucce(Node *root, Node *temp){
    if(temp->right!=NULL){
        return minVal(temp->right);
    }

    Node *succ = NULL;
    while(root!=NULL){
        if(temp->data < root->data){
            succ = root;
            root = root->left;
        }
        else if(root->data<temp->data){
            root=root->right;
        }
        else break;
    }

    return succ;
}

void inOrderAndPredec(Node *root, Node *&pre, Node *&succ, int k){
    if(root==NULL){
        return;
    }

    if(root->data==k){
        if(root->left!=NULL){
            Node* tmp = root->left;
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ;
        }

        if(root->right!=NULL){
            Node *tmp = root->right;
            while(tmp->left)
                tmp = tmp->left;
            succ = tmp;
        }
        return;
    }

    if(root->data>k){
        succ = root;
        inOrderAndPredec(root->left,pre,succ,k);
    }
    else{
        pre = root;
        inOrderAndPredec(root->right,pre,succ,k);
    }
}

int main(){
    Node *root=NULL, *temp;
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
    temp = root->left;

    // cout<<"Inorder successor of "<<temp->data<<" is "<<inOrderSucce(root,temp)->data;
    Node *pre=NULL,*succ=NULL;
    inOrderAndPredec(root,pre,succ,temp->data);
    cout<<pre->data<<" "<<succ->data;
    cout<<endl;
    return 0;
}
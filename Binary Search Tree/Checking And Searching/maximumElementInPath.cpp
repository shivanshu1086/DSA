#include <iostream>
#include <unordered_set>

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

Node *LCA(Node *root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if (root->data > n1 && root->data > n2)  
        return LCA(root->left, n1, n2);
    
    if(root->data<n1 && root->data<n2){
        return LCA(root->right,n1,n2);
    }

    return root;
}

int findMax(Node *root, int n){
    Node *p = root;

    int mx = INT_MIN;

    while(p->data!=n){
        if(p->data>n){
            mx = max(mx,p->data);
            p=p->left;
        }
        else{
            mx = max(mx,root->data);
            p=p->right;
        }
    }
    return max(mx,n);
}

int maximumElement(Node *root, int a, int b){
    Node *lca = LCA(root,a,b);

    return max(findMax(lca,a), findMax(lca,b));
}


int main(){
    int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 }; 
    int a = 1, b = 10; 
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = insert(root,arr[0]);
    for(int i=1;i<n;i++){
        insert(root,arr[i]);
    }
    cout << maximumElement(root, a, b) << endl;
    cout<<endl;
    return 0;
}
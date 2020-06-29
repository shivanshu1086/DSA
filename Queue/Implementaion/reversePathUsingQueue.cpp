#include <iostream>
#include <queue>

using namespace std;

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newnode(int x){
    struct node *temp=new node();
    temp->key=x;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root, int key){
    if(root==NULL){
        return newnode(key);
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else if(key>root->key){
        root->right=insert(root->right,key);
    }
    return root;
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void reversePath(struct node **root, int &k, queue<int> &q){
    if(root==NULL){
        return;
    }

    if((*root)->key==k){
        q.push((*root)->key);
        (*root)->key=q.front();
        q.pop();
        return;
    }

    else if(k<(*root)->key){
        q.push((*root)->key);
        reversePath(&(*root)->left,k,q);
        (*root)->key=q.front();
        q.pop();
    }
    else if((*root)->key<k){
        q.push((*root)->key);
        reversePath(&(*root)->right,k,q);
        (*root)->key=q.front();
        q.pop();
    }
    return;
}

int main(){
    struct node *root=NULL;
    queue<int> q1;
    root=insert(root,50);
    int k=80;
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    cout << "Before Reverse :" << endl; 
    inorder(root); 
  
    cout << "\n";
    reversePath(&root, k, q1); 
      
    cout << "After Reverse :" << endl;
    inorder(root); 
    cout<<endl;
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp = new node();
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void insert_in_tree(node *root, int key){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        while(count--){
            node *fnt=q.front();
            q.pop();
            if(fnt->left==NULL){
                fnt->left= newNode(key);
                return;
            }
            if(fnt->right==NULL){
                fnt->right= newNode(key);
                return;
            }
            else{
                q.push(fnt->left);
                q.push(fnt->right);
            }
        }
    }
}

void levelOrder(node *root){
    queue<node *> q;
    q.push(root);

    while(!q.empty()){
        int count=q.size();
        while(count--){
            node *fnt=q.front();
            q.pop();

            cout<<fnt->data<<" ";
            if(fnt->left!=NULL){
                q.push(fnt->left);
            }
            if(fnt->right!=NULL){
                q.push(fnt->right);
            }
        }
        cout<<endl;
    }
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
	node *root = newNode(10);
    root->left = newNode(11);
    root->right = newNode(9);
    root->left->left = newNode(7);
    root->right->left =  newNode(15); 
    root->right->right =  newNode(8);
    int key=12;
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    insert_in_tree(root,key);
    levelOrder(root);

    cout<<endl<<endl;
    cout<<"Inorder : ";
    inorder(root);
	cout<<endl;
    return 0;
}

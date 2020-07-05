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
    node *tmp=new node();
    tmp->data=x;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void levelOrder(node *root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        while(count--){
            node *tmp=q.front();
            q.pop();
            cout<<tmp->data<<" ";
            if(tmp->left!=NULL){
                q.push(tmp->left);
            }
            if(tmp->right!=NULL){
                q.push(tmp->right);
            }
        }
        cout<<endl;
    }
}

int main(){
    node *root=newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    levelOrder(root);
    cout<<endl;
	return 0;
}
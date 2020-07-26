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
    tmp->data = x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void levelOrderLineByLine(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            node *tmp = q.front();
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
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelOrderLineByLine(root);
	cout<<endl;
    return 0;
}

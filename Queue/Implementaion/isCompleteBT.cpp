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

bool isCompleteBT(node *root){
    if(root==NULL){
        return true;
    }

    queue<node *> q;
    q.push(root);
    bool flag=true;

    while(!q.empty()){
        node *tmp = q.front();
        q.pop();

        if(tmp->left){
            if(flag==true){
                return false;
            }
            q.push(tmp->left);
        }
        else{
            flag=true;
        }

        if(tmp->right){
            if(flag==true){
                return false;
            }
            q.push(tmp->right);
        }
        else{
            flag=true;
        }
    }
    return true;
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6);
    if ( isCompleteBT(root) == true ) 
        cout << "Complete Binary Tree"; 
    else
        cout << "NOT Complete Binary Tree";
    cout<<endl;
	return 0;
}
#include <iostream>
#include <queue>
#include <numeric>

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

int treeHeight(node *root){
    if(!root){
        return -1;
    }

    queue<node *> q;

    q.push(root);
    int height=0;

    while(1){
        int nodeCount=q.size();
        if(nodeCount==0){
            return height;
        }

        height++;

        while(nodeCount>0){
            node *tmp=q.front();
            q.pop();

            if(tmp->left!=NULL){
                q.push(tmp->left);
            }

            if(tmp->right!=NULL){
                q.push(tmp->right);
            }
            nodeCount--;
        }
    }
}

int main(){
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);

    cout << "Height of tree is " << treeHeight(root);
    cout<<endl;
	return 0;
}
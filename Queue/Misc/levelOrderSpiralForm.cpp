#include <iostream>
#include <queue>
#include <stack>

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

void spiralTraversal(node *root){

    if(!root){
        return;
    }


    stack<node *> currLevel;
    stack<node *> nextLevel;
    currLevel.push(root);

    bool leftToRight=true;
    while(!currLevel.empty()){
        node *tmp = currLevel.top();
        currLevel.pop();

        if(tmp){
            cout<<tmp->data<<" ";

            if(!leftToRight){
                if(tmp->left){
                    nextLevel.push(tmp->left);
                }
                if(tmp->right){
                    nextLevel.push(tmp->right);
                }
            }
            else{
                if(tmp->right){
                    nextLevel.push(tmp->right);
                }
                if(tmp->left){
                    nextLevel.push(tmp->left);
                }
            }
        }

        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}

int main(){
    node *root=newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4);

    cout<<"Spiral Traversal"<<endl;
    spiralTraversal(root);
    cout<<endl;
	return 0;
}
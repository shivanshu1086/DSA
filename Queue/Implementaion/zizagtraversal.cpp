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
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void zizagtraversal(node *root){
    if(!root){
        return;
    }

    stack<node *> currentLevel;
    stack<node *> nextLevel;

    currentLevel.push(root);

    bool leftToRight=true;
    while(!currentLevel.empty()){
        node *temp = currentLevel.top();
        currentLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currentLevel.empty()){
            leftToRight=!leftToRight;
            swap(currentLevel,nextLevel);
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
    cout << "ZigZag Order traversal of binary tree is \n";

    zizagtraversal(root);
    cout<<endl;
	return 0;
}
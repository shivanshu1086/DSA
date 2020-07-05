#include <iostream>
#include <queue>
#include <numeric>
#include <climits>

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

void maxLevelSum(node *root){
    queue<node *> q;
    q.push(root);

    int maxSum=root->data;
    while(!q.empty()){
        int count=q.size();
        int sum=0;
        while(count--){
            node *tmp=q.front();
            q.pop();

            sum+=tmp->data;

            if(tmp->left!=NULL){
                q.push(tmp->left);
            }
            if(tmp->right!=NULL){
                q.push(tmp->right);
            }
        }
        maxSum=max(maxSum,sum);
    }

    cout<<maxSum;
}

int main(){
    node *root=newNode(1);
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(8); 
    root->right->right->left  = newNode(6); 
    root->right->right->right  = newNode(7);
    /*   Constructed Binary tree is: 
                 1 
               /   \ 
             2      3 
           /  \      \ 
          4    5      8 
                    /   \ 
                   6     7    */
    maxLevelSum(root);
    cout<<endl;
	return 0;
}
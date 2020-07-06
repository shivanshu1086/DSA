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
    tmp->left=tmp->right=NULL;
    return tmp;
}

void averageOfLevels(node *root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        int k=count;
        int sum=0;
        while(k--){
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
        cout<<(float)sum/(float)count<<" ";
    }
}

int main(){
    node *root=newNode(4);
    root->left = newNode(2); 
    root->right = newNode(9); 
    root->left->left = newNode(3); 
    root->left->right = newNode(8); 
    root->right->right = newNode(7);
    averageOfLevels(root);
    cout<<endl;
	return 0;
}
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int x){
    Node *tmp = new Node();
    tmp->data = x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void modifiedLevelOrder(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    stack<Node *> s;
    bool left_to_right=true;
    int level_count=-1;
    while(!q.empty()){
        int cnt=q.size();
        level_count++;
        if(level_count==2){
            left_to_right = !left_to_right;
            level_count=0;
        }
        if(left_to_right){
            while(cnt--){
                Node *t = q.front();
                q.pop();
                cout<<t->data<<" ";
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
        }
        else{
            while(cnt--){
                Node *t = q.front();
                s.push(t);
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            while(!s.empty()){
                cout<<s.top()->data<<" ";
                s.pop();
            }
        }
        cout<<endl;
    }
}

int main(){
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(3); 
    root->left->right->right = newNode(1); 
    root->right->left->left = newNode(4); 
    root->right->left->right = newNode(2); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(2); 
    root->left->right->left->left = newNode(16); 
    root->left->right->left->right = newNode(17); 
    root->right->left->right->left = newNode(18); 
    root->right->right->left->right = newNode(19);
    modifiedLevelOrder(root);
    return 0;
}

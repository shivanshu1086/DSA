#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

struct Node { 
    int data; 
    struct Node* left, *right; 
};

struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
}

void printAncestors(struct Node *root, int key){
    if(root==NULL){
        return;
    }
    stack<struct Node *> s;
    while(1){
        while(root && root->data!=key){
            s.push(root);
            root=root->left;
        }

        if(root && root->data==key){
            break;
        }

        if(s.top()->right==NULL){
            root=s.top();
            s.pop();

            while(!s.empty() && s.top()->right==root){
                root=s.top();
                s.pop();
            }
        }
    
        root = s.empty() ? NULL : s.top()->right;
    }

    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main() {
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(7); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(8); 
    root->right->right = newNode(9); 
    root->left->left->left = newNode(4); 
    root->left->right->right = newNode(6); 
    root->right->right->left = newNode(10);

    int key = 6; 
    printAncestors(root, key);
    cout<<endl;
	return 0;
}
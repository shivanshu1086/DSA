#include <iostream>
#include <queue>

using namespace std;

struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 

struct Node* newNode(int data) 
{ 
    struct Node *temp = new struct Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node *flipBinaryTree(Node *root){
    if(root==NULL || root->left==NULL || root->right==NULL){
        return root;
    }

    Node *flippedRoot = flipBinaryTree(root->left);

    root->left->left = root->right; 
    root->left->right = root; 
    root->left = root->right = NULL;

    return flippedRoot;
}

void printLevelOrder(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        while(count--){
            Node *front= q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
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
  
    cout << "Level order traversal of given tree\n"; 
    printLevelOrder(root);
  
    root = flipBinaryTree(root); 
  
    cout << "\nLevel order traversal of the flipped"
            " tree\n"; 
    printLevelOrder(root);
    cout<<endl;
    return 0;
}
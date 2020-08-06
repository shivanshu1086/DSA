#include <iostream>
#include <queue>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
};

Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}

void printSpecificLevelOrder(Node *root){
    deque<Node *> dq;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        while(count--){
            Node *temp = q.front();
            q.pop();
            dq.push_back(temp);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        while(!dq.empty()){
            cout<<dq.front()->data<<" ";
            dq.pop_front();
            if(!dq.empty()){
                cout<<dq.back()->data<<" ";
                dq.pop_back();
            }
        }
    }
}


int main(){
    Node *root = newNode(1); 
  
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 
  
    cout << "Specific Level Order traversal of binary tree is \n"; 
    printSpecificLevelOrder(root); 
    cout<<endl;
    return 0;
}
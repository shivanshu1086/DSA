#include <iostream>
#include <stack>
#include <map>

using namespace std;

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
/* Helper function that allocates a new node 
   with the given data and NULL left and right 
   pointers.*/
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

void printTopToBottomPath(Node *current, map<Node *, Node *> parent){
    stack<Node *> stk;
    while(current){
        stk.push(current);
        current=parent[current];
    }

    while (!stk.empty()) 
    { 
        current = stk.top(); 
        stk.pop(); 
        cout << current->data << " "; 
    } 
    cout << endl;
}

void printRootToLeaf(Node *root){
    if(root==NULL){
        return;
    }

    stack<Node*> nodeStack; 
    nodeStack.push(root);

    map<Node*, Node*> parent;
    parent[root] = NULL;


    while(!nodeStack.empty()){
        Node* current = nodeStack.top(); 
        nodeStack.pop();

        if (!(current->left) && !(current->right)) //if it is leaf node
            printTopToBottomPath(current, parent);

        if(current->right){
            parent[current->right] = current;
            nodeStack.push(current->right);
        }

        if(current->left){
            parent[current->left] = current;
            nodeStack.push(current->left);
        }
    }

}


int main(){
    Node* root = newNode(10); 
    root->left = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(2);

    printRootToLeaf(root);
    cout<<endl;
    return 0;
}
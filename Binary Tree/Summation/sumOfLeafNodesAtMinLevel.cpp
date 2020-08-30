#include <iostream>
#include <queue>
using namespace std;

struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
// function to get a new node 
Node* getNode(int data) 
{ 
    // allocate space 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
  
    // put in the data 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 

int sumOfLeafNodesAtMinLevel(Node* root) 
{
    if (!root) 
        return 0; 
  
    // if there is only one node 
    if (!root->left && !root->right) 
        return root->data; 
  
    // queue used for level order traversal 
    queue<Node*> q; 
    int sum = 0;  
    bool f = 0; 
  
    // push root node in the queue 'q' 
    q.push(root); 

    while (f == 0) { 
  
        // count number of nodes in the 
        // current level 
        int nc = q.size(); 
  
        // traverse the current level nodes 
        while (nc--) { 
  
            // get front element from 'q' 
            Node* top = q.front(); 
            q.pop(); 
  
            // if it is a leaf node 
            if (!top->left && !top->right) { 
  
                // accumulate data to 'sum' 
                sum += top->data; 
  
                // set flag 'f' to 1, to signify  
                // minimum level for leaf nodes  
                // has been encountered 
                f = 1; 
            } 
            else { 
  
                // if top's left and right child  
                // exists, then push them to 'q' 
                if (top->left) 
                    q.push(top->left); 
                if (top->right) 
                    q.push(top->right); 
            } 
        } 
    } 
  
    // required sum 
    return sum; 
}

int main(){
    Node* root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->left->right->left = getNode(8); 
    root->right->left->right = getNode(9); 
  
    cout << "Sum = "
         << sumOfLeafNodesAtMinLevel(root);
    cout<<endl;
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
};

node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}

void diagonalPrint(node* root) 
{ 
    // base case 
    if (root == NULL) 
        return; 
  
    // inbuilt queue of Treenode 
    queue<node*> q; 
  
    // push root 
    q.push(root); 
  
    // push delimiter 
    q.push(NULL); 
  
    while (!q.empty()) { 
        node* temp = q.front(); 
        q.pop(); 
  
        // if current is delimiter then insert another 
        // for next diagonal and cout nextline 
        if (temp == NULL) { 
  
            // if queue is empty return 
            if (q.empty()) 
                return; 
  
            // output nextline 
            cout << endl; 
  
            // push delimiter again 
            q.push(NULL); 
        } 
        else { 
            while (temp) { 
                cout << temp->data << " "; 
  
                // if left child is present  
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 
  
                // current equals to right child 
                temp = temp->right; 
            } 
        } 
    } 
} 

int main(){
    node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
    diagonalPrint(root);
    cout<<endl;
    return 0;
}
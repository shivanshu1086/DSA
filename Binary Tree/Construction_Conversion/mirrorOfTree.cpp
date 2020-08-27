#include <iostream>
#include<queue>
using namespace std;

struct Node  
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 

struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*) 
                         malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
      
    return(node); 
}
//Recursive approach

// void mirror(Node *node){
//     if(node==NULL){
//         return;
//     }
//     else{
//         struct Node *temp;
//         mirror(node->left);
//         mirror(node->right);

//         temp=node->left;
//         node->left=node->right;
//         node->right=temp;
//     }
// }
void mirror(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    queue<Node*> q; 
    q.push(root); 
  
    // Do BFS. While doing BFS, keep swapping 
    // left and right children 
    while (!q.empty()) 
    { 
        // pop top node from queue 
        Node* curr = q.front(); 
        q.pop(); 
  
        // swap left child with right child 
        swap(curr->left, curr->right); 
  
        // push left and right children 
        if (curr->left) 
            q.push(curr->left); 
        if (curr->right) 
            q.push(curr->right); 
    } 
}

void inOrder(struct Node* node)  
{ 
    if (node == NULL)  
        return; 
      
    inOrder(node->left); 
    cout << node->data << " "; 
    inOrder(node->right); 
}


int main(){
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
      
    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl; 
    inOrder(root);

    mirror(root);

    cout << "\nInorder traversal of the mirror tree"
         << " is \n";  
    inOrder(root); 
    cout<<endl;
    return 0;
}
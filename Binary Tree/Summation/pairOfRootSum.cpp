#include <iostream>
#include <unordered_set>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 

struct Node* newnode(int data) 
{ 
    struct Node* Node = 
            (struct Node*)malloc(sizeof(struct Node)); 
      
    Node->data = data; 
    Node->left = Node->right = NULL; 
  
    return Node; 
} 

int isPathSumHas(Node *root, unordered_set<int> &s, int x){
    if (root == NULL) 
        return false;
    
    int rem = x - root->data;

    if (s.find(rem) != s.end()) 
        return true;
    
    s.insert(root->data);

    bool res = isPathSumHas(root->left,s,x) || isPathSumHas(root->right,s,x);

    s.erase(root->data);

    return res;
}

bool isPathSum(Node *root){
    unordered_set<int> s;
    return isPathSumHas(root->left, s, root->data) || isPathSumHas(root->right,s,root->data);
}


int main(){
    struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    isPathSum(root)? cout << "Yes" : cout << "No";
    cout<<endl;
    return 0;
}
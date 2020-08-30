#include <iostream>

using namespace std;

class Node 
{ 
public: 
    int data; 
    Node* left, *right; 
    
};

Node* getNode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

int countSubtreesWithSumXUtil(Node* root, int x) 
{
    static int count=0; 
    static Node* ptr=root;

    int l=0,r=0; 
    if(root==NULL) 
    return 0;

    l+=countSubtreesWithSumXUtil(root->left,x); 
      
    r+=countSubtreesWithSumXUtil(root->right,x); 
  
    if(l+r+root->data==x) 
    count++; 


    if(ptr!=root)
        return l+root->data+r; 
      
    return count;
}

int main(){
    Node* root = getNode(5); 
    root->left = getNode(-10); 
    root->right = getNode(3); 
    root->left->left = getNode(9); 
    root->left->right = getNode(8); 
    root->right->left = getNode(-4); 
    root->right->right = getNode(7); 
  
    int x = 7; 
  
    cout << "Count = "
        << countSubtreesWithSumXUtil(root, x);
    cout<<endl;
    return 0;
}
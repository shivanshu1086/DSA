#include <iostream>
#include <vector>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
// Utility function to create new Node 
Node* newNode(int val) 
{ 
    Node* temp = new Node; 
    temp->data = val; 
    temp->left = temp->right = NULL;  
    return temp; 
} 

void storeInorder(Node* root, vector<int> &v) 
{ 
    if (!root) 
        return; 
    storeInorder(root->left, v); 
    v.push_back(root->data); 
    storeInorder(root->right, v); 
} 

bool checkBSTs(Node* root1, Node* root2) 
{
    if (!root1 && !root2)  
        return true; 
    if ((root1 && !root2) || (!root1 && root2)) 
        return false;

    vector<int> v1, v2; 
    storeInorder(root1, v1); 
    storeInorder(root2, v2);

    return (v1==v2);
}

int main(){
    Node* root1 = newNode(15); 
    root1->left = newNode(10); 
    root1->right = newNode(20); 
    root1->left->left = newNode(5); 
    root1->left->right = newNode(12); 
    root1->right->right = newNode(25);

    Node* root2 = newNode(15); 
    root2->left = newNode(12); 
    root2->right = newNode(20); 
    root2->left->left = newNode(5); 
    root2->left->left->right = newNode(10); 
    root2->right->right = newNode(25); 

    if (checkBSTs(root1, root2)) 
        cout << "YES"; 
    else
        cout << "NO"; 
    cout<<endl;
    return 0;
}
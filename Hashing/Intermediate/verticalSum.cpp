#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new 
// Binary Tree node 
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void verticalSumUtil(Node *root, int vd, map<int,int> &map){
    if(root==NULL){
        return;
    }
    map[vd] += root->data;
    verticalSumUtil(root->left, vd-1, map);
    verticalSumUtil(root->right,vd+1,map);
}

void verticalSum(Node *root) 
{
    map<int,int> map;
    verticalSumUtil(root, 0, map);
    for(auto i:map){
        cout<<i.first<<" "<<i.second<<endl;
    }
}


int main() {
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
  
    cout << "Following are the values of vertical"
            " sums with the positions of the "
            "columns with respect to root\n"; 
    verticalSum(root);
    cout<<endl;
	return 0;
}
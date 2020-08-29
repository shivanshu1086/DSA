#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp = new node();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// bool isLeaf(node *node) 
// { 
//    if (node == NULL) 
//        return false; 
//    if (node->left == NULL && node->right == NULL) 
//        return true; 
//    return false; 
// }

void rightLeavesSumRec(node *root, bool isright, int *sum){
    if (!root) return; 
  
    // Check whether this node is a leaf node and is left.
    if (!root->left && !root->right && isright) 
        *sum += root->data; 
  
    // Pass 1 for left and 0 for right 
    rightLeavesSumRec(root->right,  1, sum); 
    rightLeavesSumRec(root->left, 0, sum);
}

int rightLeavesSum(node *root) 
{ 
    int sum = 0; //Initialize result 
  
    // use the above recursive function to evaluate sum 
    rightLeavesSumRec(root, 0, &sum); 
  
    return sum; 
}


int main(){
    node *root = newNode(1);
    root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->right = newNode(2); 
    root->right = newNode(3); 
    root->right->right = newNode(8); 
    root->right->right->left = newNode(6); 
    root->right->right->right = newNode(7);
    cout << "Sum of left leaves is "
         << rightLeavesSum(root);

    cout<<endl;
    return 0;
}
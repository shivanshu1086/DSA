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

void leftLeavesSumRec(node *root, bool isleft, int *sum){
    if (!root) return; 
  
    // Check whether this node is a leaf node and is left. 
    if (!root->left && !root->right && isleft) 
        *sum += root->data; 
  
    // Pass 1 for left and 0 for right 
    leftLeavesSumRec(root->left,  1, sum); 
    leftLeavesSumRec(root->right, 0, sum);
}

int leftLeavesSum(node *root) 
{ 
    int sum = 0; //Initialize result 
  
    // use the above recursive function to evaluate sum 
    leftLeavesSumRec(root, 0, &sum); 
  
    return sum; 
}


int main(){
    node *root = newNode(20);
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12); 
    cout << "Sum of left leaves is "
         << leftLeavesSum(root); 

    cout<<endl;
    return 0;
}
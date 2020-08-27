#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp=new node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

int search(int arr[], int strt, int end, int value) 
{ 
    for (int i = strt; i <= end; i++) 
    { 
        if(arr[i] == value) 
            return i; 
    }
    return -1;
}

node *buildTree(int in[], int pre[], int inStrt, int inEnd){
    static int preIndex = 0; 
   
    if(inStrt > inEnd) 
        return NULL; 
   
    /* Pick current node from Preorder traversal  
       using preIndex and increment preIndex */
    node *tNode = newNode(pre[preIndex++]); 
   
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return tNode; 
   
    /* Else find the index of this node in  
       Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data); 
   
    /* Using index in Inorder traversal,  
       construct left and right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex-1); 
    tNode->right = buildTree(in, pre, inIndex+1, inEnd); 
   
    return tNode;
}

bool checkPostorder(node *root, int postOrder[]){
    static int postIndex=0;
    if(root==NULL){
        return false;
    }

    else{
        checkPostorder(root->left, postOrder);
        checkPostorder(root->right, postOrder);
        if(root->data!=postOrder[postIndex++]){
            return false;
        }
    }
    return true;
}



int main(){
    int inOrder[] = {4, 2, 5, 1, 3}; 
    int preOrder[] = {1, 2, 4, 5, 3}; 
    int postOrder[] = {4, 5, 2, 3, 1}; 
  
    int len = sizeof(inOrder)/sizeof(inOrder[0]); 
  
    // build tree from given  
    // Inorder and Preorder traversals 
    node *root = buildTree(inOrder, preOrder, 0, len - 1); 
  
  
    // If both postorder traversals are same  
    if (checkPostorder(root,postOrder)) 
        cout << "Yes"; 
    else
        cout << "No";

    
    cout<<endl;
    return 0;
}
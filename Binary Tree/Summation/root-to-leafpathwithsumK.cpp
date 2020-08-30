#include <iostream>

using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  

node* newnode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  

bool hasPathSum(node* Node, int sum)  
{  
    /* return true if we run out of tree and sum==0 */
    if (Node == NULL)  
    {  
        return (sum == 0);  
    }  
      
    else
    {  
        bool ans = 0;  
      
        /* otherwise check both subtrees */
        int subSum = sum - Node->data;  
      
        /* If we reach a leaf node and sum becomes 0 then return true*/
        if ( subSum == 0 && Node->left == NULL && Node->right == NULL )  
        return 1;  
      
        if(Node->left)  
            ans = ans || hasPathSum(Node->left, subSum);  
        if(Node->right)  
            ans = ans || hasPathSum(Node->right, subSum);  
      
        return ans;  
    }  
}

int main(){
    int sum = 21;
    node *root = newnode(10);  
    root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);  
    root->right->left = newnode(2);  
      
    if(hasPathSum(root, sum))  
        cout << "There is a root-to-leaf path with sum " << sum;  
    else
        cout << "There is no root-to-leaf path with sum " << sum;
    cout<<endl;
    return 0;
}
#include <iostream>

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

int calulateSum(int path[],int pathLen){
    int sum=0;
    for (int i = 0; i < pathLen; i++) 
    {  
        sum+=path[i];
    }
    return sum;
}

void printPathsRecur(Node *node, int path[], int pathLen, int &ans){
    if(node==NULL)return;

    path[pathLen] = node->data;
    pathLen++;

    if (node->left == NULL && node->right == NULL){ 
        int sum = calulateSum(path, pathLen);
        ans = max(sum,ans);
    }
    else{
        printPathsRecur(node->left,path,pathLen,ans);
        printPathsRecur(node->right,path,pathLen,ans);
    }
}

int largestSum(Node *root){
    int path[1000];  
    int ans=INT_MIN;
    printPathsRecur(root, path, 0, ans);
    return ans;
}


int main(){
    Node* root = newnode(4);         
    root->left = newnode(2);         
    root->right = newnode(5);        
    root->left->left = newnode(7);   
    root->left->right = newnode(1);  
    root->right->left = newnode(2);  
    root->right->right = newnode(3); 
    root->left->right->left = newnode(6);

    cout<<"Sum: "<<largestSum(root);
    cout<<endl;
    return 0;
}
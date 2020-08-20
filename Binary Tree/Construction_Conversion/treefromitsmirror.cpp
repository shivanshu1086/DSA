#include <iostream>

using namespace std;

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
};

node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}
void printInorder(node* Node) 
{ 
    if (Node == NULL) 
        return; 
  
    printInorder(Node->left); 
    printf("%d ", Node->data); 
    printInorder(Node->right); 
}

node *constructBinaryTreeUtil(int pre[], int preM[], int &preIndex, int l, int h, int size){
    if(preIndex>=size||l>h){
        return NULL;
    }

    node *root = newNode(pre[preIndex]);
    ++(preIndex);

    if(l==h){
        return root;
    }

    int i;
    for(i=l;i<=h;i++){
        if(pre[preIndex]==preM[i]){
            break;
        }
    }

    if(i<=h){
        root->left = constructBinaryTreeUtil (pre, preM, preIndex, i, h, size);
        root->right = constructBinaryTreeUtil (pre, preM, preIndex, l+1, i-1, size);
    }
    return root;
}

void constructBinaryTree(node *root,int pre[], int preMirror[], int size){
    int preIndex = 0;
    int preMIndex = 0;
    root =  constructBinaryTreeUtil(pre,preMirror,preIndex,0,size-1,size);
    printInorder(root);
}


int main(){
    int preOrder[] = {1,2,4,5,3,6,7}; 
    int preOrderMirror[] = {1,3,7,6,2,5,4};
    int size = sizeof(preOrder)/sizeof(preOrder[0]);
    node *root = new node;
    constructBinaryTree(root,preOrder,preOrderMirror,size);
    cout<<endl;
    return 0;
}
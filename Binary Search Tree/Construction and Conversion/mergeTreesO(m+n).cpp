#include <iostream>

using namespace std;

class Node  
{  
    public: 
    int data;  
    Node *left;  
    Node *right;  
};  

Node * newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}  

void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    
    printInorder(root->left);
    cout << root->data << " "; 
    printInorder(root->right); 
}

void storeInOrder(int *arr, Node *root, int *i){
    if(root==NULL){
        return;
    }

    storeInOrder(arr,root->left,i);
    arr[(*i)++] = root->data;
    storeInOrder(arr,root->right,i);
}

int *mergeArr(int *arr1, int *arr2, int m, int n){
    int k=0;
    int i=0,j=0;
    int *mergeArr = new int[m+n];

    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            mergeArr[k]=arr1[i++];
        }
        else{
            mergeArr[k]=arr2[j++];
        }
        k++;
    }

    while(i<m){
        mergeArr[k++] = arr1[i++];
    }

    while(j<n){
        mergeArr[k++] = arr2[j++];
    }

    return mergeArr;
}

Node *sortedArrayToBST(int *arr, int start, int end){
    if(start>end){
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);
    return root;
}

Node* mergeTrees(Node *root1, Node *root2, int m, int n)  
{
    int *arr1 = new int[m];
    int i=0;
    storeInOrder(arr1,root1,&i);

    int *arr2 = new int[n];
    int j=0;
    storeInOrder(arr2,root2,&j);

    int *arr = mergeArr(arr1,arr2,m,n);

    return sortedArrayToBST (arr, 0, m + n - 1);
}


int main(){
    Node *root1 = newNode(100);  
    root1->left     = newNode(50);  
    root1->right = newNode(300);  
    root1->left->left = newNode(20);  
    root1->left->right = newNode(70);

    Node *root2 = newNode(80);  
    root2->left     = newNode(40);  
    root2->right = newNode(120);

    Node *mergedTree = mergeTrees(root1, root2, 5, 3);
  
    cout << "Following is Inorder traversal of the merged tree \n";  
    printInorder(mergedTree);
    cout<<endl;
    return 0;
}
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    int leftSize;
};

Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->leftSize = 0;
    return temp;
}

Node *insert(Node *&root, int data){
    if(root==NULL){
        return newNode(data);
    }

    if(root->data>data){
        root->left =  insert(root->left,data);
        root->leftSize++;
    }
    else{
        root->right =  insert(root->right,data);
    }
    return root;
}

int getRank(Node* root, int x) 
{
    if(root==NULL){
        return root->leftSize;
    }

    if (x < root->data) { 
        if (!root->left) 
            return -1; 
        else
            return getRank(root->left, x); 
    }

    else { 
        if (!root->right) 
            return -1; 
        else { 
            int rightSize = getRank(root->right, x); 
            return root->leftSize + 1 + rightSize; 
        } 
    } 
}





int main(){
    int arr[] = { 5, 1, 4, 4, 5, 9, 7, 13, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 4; 
  
    Node* root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, arr[i]); 
  
    cout << "Rank of " << x << " in stream is: " 
         << getRank(root, x)+1 << endl; 
  
    x = 13; 
    cout << "Rank of " << x << " in stream is: "
         << getRank(root, x)+1 << endl;
    cout<<endl;
    return 0;
}
#include <iostream>
#define MAX 100
using namespace std;

struct Node { 
    char key; 
    struct Node *left, *right; 
}; 

Node* newNode(char item) 
{ 
    Node* temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void storeInorder(Node *root, char arr[], int &m){
    if(root==NULL){
        arr[m++]='$';
        return;
    }

    storeInorder(root->left, arr, m);
    arr[m++] = root->key;
    storeInorder(root->right, arr, m);
}

void storePreOrder(Node *root, char arr[], int &m){
    if(root==NULL){
        arr[m++]='$';
        return;
    }

    arr[m++]=root->key;
    storePreOrder(root->left, arr, m);
    storePreOrder(root->right,arr,m);
}

bool isSubtree(Node *T, Node *S){
    if (S == NULL) 
        return true; 
    if (T == NULL) 
        return false;

    int m = 0, n = 0; 
    char inT[MAX], inS[MAX];

    storeInorder(T, inT, m); 
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';

    if(strstr(inT,inS)==NULL){
        return false;
    }

    m = 0, n = 0; 
    char preT[MAX], preS[MAX]; 
    storePreOrder(T, preT, m); 
    storePreOrder(S, preS, n); 
    preT[m] = '\0', preS[n] = '\0';

    return (strstr(preT, preS) != NULL);
}

int main(){
    Node* T = newNode('a'); 
    T->left = newNode('b'); 
    T->right = newNode('d'); 
    T->left->left = newNode('c'); 
    T->right->right = newNode('e'); 
  
    Node* S = newNode('a'); 
    S->left = newNode('b'); 
    S->left->left = newNode('c'); 
    S->right = newNode('d'); 
  
    if (isSubtree(T, S)) 
        cout << "Yes: S is a subtree of T"; 
    else
        cout << "No: S is NOT a subtree of T";
    cout<<endl;
    return 0;
}
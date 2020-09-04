#include <iostream>

using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
};

struct Node* newNode(int item) 
{ 
    struct Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node *insert(Node *root, int x){
    if(root==NULL){
        return newNode(x);
    }
    if(root->data>x){
        root->left = insert(root->left,x);
    }
    else if(root->data<x){
        root->right = insert(root->right,x);
    }
    return root;
}

void convertBSTtoDLL(Node *root, Node **head, Node **tail){
    if (root == NULL)  
        return;

    if(root->left){
        convertBSTtoDLL(root->left,head,tail);
    }

    root->left = *tail;

    if (*tail)  
        (*tail)->right = root;  
    else
        *head = root;

    *tail = root;

    if (root->right)  
        convertBSTtoDLL(root->right, head, tail);
}

bool isPresentInDLL(Node* head, Node* tail, int sum)
{
    while (head != tail)  
    {  
        int curr = head->data + tail->data;
        if (curr == sum)  
            return true;  
        else if (curr > sum)  
            tail = tail->left;  
        else
            head = head->right;  
    }  
    return false;
}

bool isTripletPresent(Node *root){
    if (root == NULL)  
    return false;

    Node* head = NULL;  
    Node* tail = NULL;  
    convertBSTtoDLL(root, &head, &tail);

    while ((head->right != tail) && (head->data < 0))  
    {
        if (isPresentInDLL(head->right, tail, -1*head->data))  
            return true;  
        else
            head = head->right;
    }
    return false;
}


int main(){
    Node* root = NULL;  
    root = insert(root, 6);  
    root = insert(root, -13);  
    root = insert(root, 14);  
    root = insert(root, -8);  
    root = insert(root, 15);  
    root = insert(root, 13);  
    root = insert(root, 7);  
    if (isTripletPresent(root))  
        cout << "Present";  
    else
        cout << "Not Present";
    cout<<endl;
    return 0;
}
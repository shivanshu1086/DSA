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

void convertTreeToDLL(Node *root, Node **head, Node **tail){
    if(root==NULL){
        return;
    }

    if(root->left){
        convertTreeToDLL(root->left,head,tail);
    }

    root->left = *(tail);

    if(*tail){
        (*tail)->right = root;
    }
    else{
        *head = root;
    }

    *tail = root;

    if(root->right){
        convertTreeToDLL(root->right,head,tail);
    }
}

bool is_present(Node *head, Node *tail, int x, int target){
    while(head!=NULL){
        if(head->data+x==target){
            return true;
        }
        else{
            head=head->right;
        }
    }
    return false;
}

bool isPairPresent(Node *root, int target){
    Node *head, *tail;
    convertTreeToDLL(root, &head, &tail);
    while(head!=tail){
        if(is_present(head->right,tail,head->data,target)){
            return true;
        }
        else{
            head=head->right;
        }
    }
    return false;
}

int main(){
    Node* root = newNode(15); 
    root->left = newNode(10); 
    root->right = newNode(20); 
    root->left->left = newNode(8); 
    root->left->right = newNode(12); 
    root->right->left = newNode(16); 
    root->right->right = newNode(25);

    int target = 33; 
    if (isPairPresent(root, target) == false) 
        cout << "\nNo such values are found\n";
    else{
        cout<<"Found!";
    }
    cout<<endl;
    return 0;
}
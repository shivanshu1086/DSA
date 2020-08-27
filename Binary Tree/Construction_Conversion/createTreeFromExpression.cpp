#include <iostream>

using namespace std;

struct Node 
{ 
    char data; 
    Node *left, *right; 
}; 

Node *newNode(char Data) 
{ 
    Node *new_node = new Node; 
    new_node->data = Data; 
    new_node->left = new_node->right = NULL; 
    return new_node; 
}

Node *createTree(string str, int & i){
    Node *root = newNode(str[i]);
    if(i==str.length()-1) return root;//!if it is last char

    i++;

    if(str[i]=='?'){
        i++;//skip it
        root->left = createTree(str,i);
        i++;
        root->right = createTree(str,i);
        return root;
    }
    else{
        return root;
    }
}

void printTree(Node *root){
    if(root==NULL){
        return;
    }
    else{
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }
}

int main(){
    string expression = "a?b?c:d:e"; 
    int i=0;
    Node *root = createTree(expression,i);
    printTree(root);
    cout<<endl;
    return 0;
}
#include <iostream>
#include <list>
using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};
list<node*> l;
node* newNode(int data)  
{  
    node* new_node = new node();  
    new_node->data = data;  
    new_node->left = new_node->right = NULL;  
    return (new_node);  
}  

void createInorderDLL(node *root){
    if(root==NULL){
        return;
    }
    else{
        createInorderDLL(root->left);
        l.push_back(root);
        createInorderDLL(root->right);
    }
}

int main(){
    node *root = newNode(10);  
    root->left = newNode(12);
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);  

    createInorderDLL(root);
    for(auto it=l.rbegin();it!=l.rend();it++){
        cout<<(*it)->data<<" ";
    }
    cout<<endl;
    for(auto i:l){
        cout<<i->data<<" ";
    }
    cout<<endl;
    return 0;
}
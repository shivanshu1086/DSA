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

bool inRange(Node* root, int low, int high) 
{ 
    return root->data >= low && root->data <= high; 
}

bool getCountUtil(Node* root, int low, int high, int* count) 
{
    if(root==NULL){
        return true;
    }

    bool l = getCountUtil(root->left,low,high,count);
    bool r = getCountUtil(root->right,low,high,count);

    if(l && r && inRange(root,low,high)){
        ++*count;
        return true;
    }

    return false;
}

int getCount(Node* root, int low, int high) 
{ 
    int count = 0; 
    getCountUtil(root, low, high, &count); 
    return count; 
}

int main(){
    Node* root = newNode(10); 
    root->left = newNode(5); 
    root->right = newNode(50); 
    root->left->left = newNode(1); 
    root->right->left = newNode(40); 
    root->right->right = newNode(100);

    int l = 5; 
    int h = 45; 
    cout << "Count of subtrees in [" << l << ", "
         << h << "] is " << getCount(root, l, h);
    
    cout<<endl;
    return 0;
}
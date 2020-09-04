#include <iostream>
#include <unordered_set>

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

bool findpairUtil(Node *root, int sum, unordered_set<int> &set){
    if(root==NULL){
        return false;
    }

    if(findpairUtil(root->left,sum,set)) return true;

    if(set.find(sum-root->data)!=set.end()){
        cout<< "Pair is found ("
             << sum - root->data << ", "
             << root->data << ")" << endl;
        return true;
    }
    else{
        set.insert(root->data);
    }

    return findpairUtil(root->right,sum,set);
}

void findPair(Node *root, int sum){
    unordered_set<int> set;
    if (!findpairUtil(root, sum, set)) 
        cout << "Pairs do not exit" << endl;
}

int main(){
    Node* root = NULL; 
    root = insert(root, 15); 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 12); 
    root = insert(root, 16); 
    root = insert(root, 25); 
    root = insert(root, 10); 
  
    int sum = 33; 
    findPair(root, sum);
    cout<<endl;
    return 0;
}
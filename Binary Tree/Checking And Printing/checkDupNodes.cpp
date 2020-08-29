#include <iostream>
#include <map>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp = new node();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void calculateDup(node *root, map<int,int> &mp){
    if(root==NULL){
        return;
    }
    else{
        mp[root->data]++;
        calculateDup(root->left,mp);
        calculateDup(root->right,mp);
    }
}

bool checkDup(node *root){
    map<int, int> mp;

    calculateDup(root, mp);

    for(auto i:mp){
        if(i.second>1){
            return true;
        }
    }
    return false;
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3);

    if (checkDup(root)) 
        printf("Yes"); 
    else
        printf("No"); 
    cout<<endl;
    return 0;
}
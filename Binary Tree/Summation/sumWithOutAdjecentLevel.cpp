#include <iostream>
#include <queue>
using namespace std;

class Node 
{ 
public: 
    int data; 
    Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = NULL; 
        right = NULL; 
    } 
};

int findSum(Node *root, bool odd_even){
    if(root==NULL){
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    int sum = 0;
    while(!q.empty()){
        int count = q.size();
        if(odd_even){
            while(count--){
                Node *temp = q.front();
                q.pop();
                sum+=temp->data;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        else{
            while(count--){
                Node *temp = q.front();
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        odd_even=!odd_even;
    }
    return sum;
}

int getSum(Node *root){
    int sumOne = findSum(root,1);
    int sumTwo = findSum(root,0);

    return max(sumOne,sumTwo);
}

int main(){
    Node* root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->right->left = new Node(4);  
    root->right->left->right = new Node(5);  
    root->right->left->right->left = new Node(6);  
    cout << (getSum(root));
    cout<<endl;
    return 0;
}
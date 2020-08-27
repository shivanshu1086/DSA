#include <iostream>
#include <deque>
#include <stack>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
};

Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
}

void push(Node **head, Node *top){
    top->right=(*head);
    top->left=NULL;

    if((*head)!=NULL){
        (*head)->left=top;
    }

    (*head)=top;
}

void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}

void spiralLevelOrder(Node *root){
    if(root==NULL){
        return;
    }
    deque<Node *> q;
    q.push_front(root);

    stack<Node *> stk;

    int level=0;

    while(!q.empty()){
        int nodeCount = q.size();

        //assume level starts from 0;
        if(level&1){//! odd level if it is (condition for checking)
            //this condition is for left to right printing
            while(nodeCount>0){
                Node *node = q.front();
                q.pop_front();
                stk.push(node);

                if(node->left!=NULL){
                    q.push_back(node->left);
                }
                if(node->right!=NULL){
                    q.push_back(node->right);
                }

                nodeCount--;
            }
        }

        else{//even level
            //right to left printing
            while(nodeCount>0){
                Node *node = q.back();
                q.pop_back();
                stk.push(node);

                if(node->right!=NULL){
                    q.push_front(node->right);
                }

                if(node->left!=NULL){
                    q.push_front(node->left);
                }
                
                nodeCount--;
            }
        }
        level++;
    }

    Node *head = NULL;

    while(!stk.empty()){
        push(&head, stk.top());
        stk.pop();
    }
    cout << "Created DLL is:\n";
    printList(head);
}


int main(){
    Node *root =  newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14);
    spiralLevelOrder(root);
    cout<<endl;
    return 0;
}
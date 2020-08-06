#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
};

Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}

void specific_level_order_traversal(Node* root) 
{ 
    //for level order traversal 
    queue <Node*> q; 
    // stack to print reverse 
    stack < vector <int> > s;  
      
    q.push(root); 
    int sz; 
      
    while(!q.empty()) 
    { 
        vector <int> v;    //vector to store the level 
        sz = q.size();    //considering size of the level 
          
        for(int i=0;i<sz;++i) 
        { 
            Node* temp = q.front(); 
            q.pop(); 
              
            //push data of the node of a particular level to vector 
            v.push_back(temp->data);  
              
            if(temp->left!=NULL) 
            q.push(temp->left); 
      
            if(temp->right!=NULL) 
                q.push(temp->right); 
        } 
          
        //push vector containg a level in stack 
        s.push(v);  
    } 
      
    //print the stack 
    while(!s.empty()) 
    { 
        // Finally pop all Nodes from stack and prints 
        // them. 
        vector <int> v = s.top(); 
        s.pop(); 
        for(int i=0,j=v.size()-1;i<j;++i) 
            { 
                cout<<v[i]<<" "<<v[j]<<" "; 
                j--; 
            } 
    } 
      
    //finally print root; 
    cout<<root->data; 
      
} 

void printSpecificLevelOrderUtil(Node *root, stack<Node *> &s){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root->left);
    q.push(root->right);

    Node *first=NULL,*second =NULL;

    while(!q.empty()){
        first = q.front();
        q.pop();
        second = q.front();
        q.pop();

        s.push(second->left);
        s.push(first->right);
        s.push(second->right);
        s.push(first->left);

        if(first->left->left!=NULL){
            q.push(first->right); 
            q.push(second->left); 
            q.push(first->left); 
            q.push(second->right);
        }
    }

}

void printSpecificLevelOrder(Node *root){
    stack<Node *> s;
    s.push(root);
    if(root->left!=NULL){
        s.push(root->right);
        s.push(root->left);
    }

    if(root->left->left!=NULL){
        printSpecificLevelOrderUtil(root, s);
    }

    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}


int main(){
    Node *root = newNode(1); 
  
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 
  
    cout << "Specific Level Order traversal of binary "
         "tree is \n"; 
    printSpecificLevelOrder(root);
    cout<<endl;
    return 0;
}
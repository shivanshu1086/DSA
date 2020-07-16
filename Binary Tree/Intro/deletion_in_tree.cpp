#include <iostream>
#include <queue>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp = new node();
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}


void inorder(node *root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void deleteNode(node *root, node *d_node){
    queue<node *> q;
    q.push(root);

    node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp == d_node){
            temp = NULL;
            delete (d_node);
            return;
        }

        if(temp->right){
            if(temp->right==d_node){
                temp->right=NULL;
                delete (d_node);
                return;
            }
            else{
                q.push(temp->right);
            }
        }

        if(temp->left){
            if(temp->left==d_node){
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
}

node *deletion_in_tree(node *root, int key){
    if(root==NULL){
        return NULL;
    }


    if(root->left==NULL && root->right==NULL){
        if(root->data==key){
            return NULL;
        }
        else{
            return root;
        }
    }

    queue<node *> q;
    q.push(root);

    node *temp;
    node *key_node = NULL;

    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->data==key){
            key_node=temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    if(key_node!=NULL){
        int x=temp->data;
        deleteNode(root,temp);
        key_node->data=x;
    }

    return root;
}


int main(){
	node *root = newNode(10);
    root->left = newNode(11);
    root->right = newNode(9);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right->left =  newNode(15); 
    root->right->right =  newNode(8);
    cout<<"Inorder : ";
    cout<<endl;
    inorder(root);
    cout<<endl;
    int key=11;
    root = deletion_in_tree(root,key);
    inorder(root);
	cout<<endl;
    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

class listNode{
public:
    int data;
    listNode *next;
};

class treeNode{
public:
    int data;
    treeNode *left;
    treeNode *right;
};

void push(listNode **head, int x){
    listNode *temp=new listNode();
    temp->data=x;
    temp->next=(*head);
    (*head)=temp;
}

treeNode *newtreeNode(int x){
    treeNode *tmp = new treeNode();
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void llToBinaryTree(listNode *head, treeNode *&root){
    queue<treeNode *> q;

    if(head==NULL){
        root=NULL;
        return;
    }

    root = newtreeNode(head->data);
    q.push(root);

    head=head->next;

    while(head){
        treeNode *parent=q.front();
        q.pop();

        treeNode *left, *right;
        left=NULL;
        right=NULL;

        left=newtreeNode(head->data);
        q.push(left);
        head=head->next;

        if(head){
            right=newtreeNode(head->data);
            q.push(right);
            head=head->next;
        }

        parent->left=left;
        parent->right=right;
    }
}

void printInOrder(treeNode *root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main(){
    listNode *head=NULL;
    push(&head, 36);
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10);

    treeNode *root;
    llToBinaryTree(head,root);//tree creation
    cout<<endl<<"In order Traversal is: "<<endl;
    printInOrder(root);
    cout<<endl;
	return 0;
}
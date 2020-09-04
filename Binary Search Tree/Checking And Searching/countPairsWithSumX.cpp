#include <iostream>
#include <stack>
using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
};

struct Node* getNode(int item) 
{ 
    struct Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

int countPairs(Node *root1, Node *root2, int x){
    if (root1 == NULL || root2 == NULL) 
        return 0;
    
    stack<Node *> stk1,stk2;
    Node* top1, *top2;

    int count = 0;

    while(1){
        while(root1!=NULL){
            stk1.push(root1);
            root1=root1->left;
        }

        while(root2!=NULL){
            stk2.push(root2);
            root2=root2->right;
        }

        if(stk1.empty() || stk2.empty()){
            break;
        }

        top1=stk1.top();
        top2=stk2.top();

        if(top1->data+top2->data==x){
            count++;
            stk1.pop();
            stk2.pop();

            root1=top1->right;
            root2=top2->left;
        }

        else if(top1->data+top2->data<x){
            stk1.pop();
            root1=top1->right;
        }
        else{
            stk2.pop();
            root2=top2->left;
        }
    }
    return count;
}


int main(){
    Node* root1 = getNode(5); /*             5        */
    root1->left = getNode(3); /*           /   \      */
    root1->right = getNode(7); /*         3     7     */
    root1->left->left = getNode(2); /*    / \   / \    */
    root1->left->right = getNode(4); /*  2  4  6  8    */
    root1->right->left = getNode(6); 
    root1->right->right = getNode(8);

    Node* root2 = getNode(10); /*           10         */
    root2->left = getNode(6); /*           /   \        */
    root2->right = getNode(15); /*        6     15      */
    root2->left->left = getNode(3); /*    / \   /  \     */
    root2->left->right = getNode(8); /*  3  8  11  18    */
    root2->right->left = getNode(11); 
    root2->right->right = getNode(18);

    int x = 16; 
    cout << "Pairs = "
         << countPairs(root1, root2, x);
    cout<<endl;
    return 0;
}
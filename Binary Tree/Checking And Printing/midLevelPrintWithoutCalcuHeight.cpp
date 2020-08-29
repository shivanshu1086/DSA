#include <iostream>
using namespace std;

struct Node 
{ 
    int key; 
    struct Node* left, *right; 
};

struct Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
}

void printMiddleLevelUtil(Node* a, Node* b){
    if (a == NULL || b == NULL) 
            return;
        
    if ((b->left == NULL) && (b->right == NULL)) 
    { 
        cout << a->key << " "; 
        return; 
    }

    printMiddleLevelUtil(a->left,b->left->left);
    printMiddleLevelUtil(a->right,b->right->right);
}

void printMiddleLevel(Node* node) 
{ 
    printMiddleLevelUtil(node, node); 
}

int main(){
    Node* n1 = newNode(1); 
    Node* n2 = newNode(2); 
    Node* n3 = newNode(3); 
    Node* n4 = newNode(4); 
    Node* n5 = newNode(5); 
    Node* n6 = newNode(6); 
    Node* n7 = newNode(7); 
  
    n2->left = n4; 
    n2->right = n5; 
    n3->left = n6; 
    n3->right = n7; 
    n1->left = n2; 
    n1->right = n3; 
  
    printMiddleLevel(n1);
    cout<<endl;
    return 0;
}
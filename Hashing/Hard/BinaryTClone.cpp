#include <iostream>
#include <unordered_map>
using namespace std;

struct Node 
{ 
    int key; 
    struct Node* left, *right, *random; 
}; 

void printInorder(Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* First recur on left sutree */
    printInorder(node->left); 
  
    /* then print data of Node and its random */
    cout << "[" << node->key << " "; 
    if (node->random == NULL) 
        cout << "NULL], "; 
    else
        cout << node->random->key << "], "; 
  
    /* now recur on right subtree */
    printInorder(node->right); 
}
  
/* Helper function that allocates a new Node with the 
   given data and NULL left, right and random pointers. */
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->random = temp->right = temp->left = NULL; 
    return (temp); 
}

Node *copyLeftRightNodes(Node *tree, unordered_map<Node *, Node *> &myMap){
    if(tree==NULL){
        return NULL;
    }

    Node *cloneNode = newNode(tree->key);
    myMap[tree] = cloneNode;

    cloneNode->left= copyLeftRightNodes(tree->left,myMap);
    cloneNode->right = copyLeftRightNodes(tree->right,myMap);
    return cloneNode;
}

void copyRandom(Node *tree, Node *cloneNode, unordered_map<Node *, Node *> &mymap){
    if (cloneNode == NULL) 
        return;
    
    cloneNode->random =  mymap[tree->random];
    copyRandom(tree->left,cloneNode->left,mymap);
    copyRandom(tree->right,cloneNode->right,mymap);
}

Node *cloneTree(Node *tree){
    if (tree == NULL) 
        return NULL;
    unordered_map<Node *, Node *> myMap;

    Node *newTree = copyLeftRightNodes(tree,myMap);

    copyRandom(tree, newTree, myMap);
    return newTree;
}

int main() {
    Node *tree = newNode(1); 
    tree->left = newNode(2); 
    tree->right = newNode(3); 
    tree->left->left = newNode(4); 
    tree->left->right = newNode(5); 
    tree->random = tree->left->right; 
    tree->left->left->random = tree; 
    tree->left->right->random = tree->right;

    cout << "Inorder traversal of original binary tree is: \n"; 
    printInorder(tree);

    Node *clone = cloneTree(tree);

    cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
    printInorder(clone);
    cout<<endl;
	return 0;
}
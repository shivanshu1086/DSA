#include <iostream>
#include <unordered_set>
using namespace std;

class node{
public:
    char data;
    node *left;
    node *right;
};
const char MARKER = '$';
node *newNode(char x){
    node *temp = new node();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
unordered_set<string> subtrees;

string dupSubUtil(node *root){
    string s="";
    if (root == NULL) 
        return s + MARKER;
    
    string lStr = dupSubUtil(root->left); 
    if (lStr.compare(s) == 0) 
       return s;

    string rStr = dupSubUtil(root->right); 
    if (rStr.compare(s) == 0) 
       return s;
    
    s = s + root->data + lStr + rStr;

    if (s.length() > 3 && 
        subtrees.find(s) != subtrees.end()) 
       return ""; 

    subtrees.insert(s); 
  
    return s; 
}

int main(){
    node *root = newNode('A');\
    root->left = newNode('B'); 
    root->right = newNode('C'); 
    root->left->left = newNode('D'); 
    root->left->right = newNode('E'); 
    root->right->right = newNode('B'); 
    root->right->right->right = newNode('E'); 
    root->right->right->left= newNode('D');

    string str = dupSubUtil(root);

    (str.compare("") == 0) ? cout << " Yes ": 
                             cout << " No " ;
    
    cout<<endl;
    return 0;
}
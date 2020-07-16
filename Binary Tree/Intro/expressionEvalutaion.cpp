#include <iostream>

using namespace std;

class node{
public:
    string s;
    node *left;
    node *right;

    node(string x){
        s=x;
    }
};

int toInt(string s){
    int num=0;

    if(s[0]!='-'){
        for(int i=0;i<s.length();i++){
            num=num*10 + (int(s[i])-48);
        }
    }
    else{
        for(int i=1;i<s.length();i++){
            num=num*10 + (int(s[i])-48);
            num=num*(-1);
        }
    }
    return num;
}

int eval(node *root){
    if(!root){
        return 0;
    }
    
    if(!root->left && !root->right){
        return toInt(root->s);
    }

    int l_val=eval(root->left);
    int r_val=eval(root->right);

    if(root->s=="+"){
        return l_val+r_val;
    }

    if (root->s=="-")  
        return l_val-r_val;  
  
    if (root->s=="*")  
        return l_val*r_val;

    return l_val/r_val;
}

int main(){
    node *root = new node("+");  
    root->left = new node("*");  
    root->left->left = new node("5");  
    root->left->right = new node("-4");  
    root->right = new node("-");  
    root->right->left = new node("100");  
    root->right->right = new node("20");  
    cout << eval(root) << endl;  
  
    delete(root);  
  
    root = new node("+");  
    root->left = new node("*");  
    root->left->left = new node("5");  
    root->left->right = new node("4");  
    root->right = new node("-");  
    root->right->left = new node("100");  
    root->right->right = new node("/");  
    root->right->right->left = new node("20");  
    root->right->right->right = new node("2");  
  
    cout << eval(root);
	cout<<endl;
    return 0;
}

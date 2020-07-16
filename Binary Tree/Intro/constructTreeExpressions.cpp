#include <iostream>
#include <stack>

using namespace std;

class node{
public:
    char data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp=new node();
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
} 

node *constructTree(char postfix[]){
    stack<node *> st;
    node *t,*t1,*t2;

    for(int i=0;i<strlen(postfix);i++){
        if(!isOperator(postfix[i])){
            t=newNode(postfix[i]);
            st.push(t);
        }
        else{
            t=newNode(postfix[i]);

            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
        }
    }

    t=st.top();
    st.pop();
    return t;
}
void inorder(node *t) 
{ 
    if(t) 
    { 
        inorder(t->left); 
        printf("%c ", t->data); 
        inorder(t->right); 
    } 
} 

int main(){
    char postfix[] = "ab+ef*g*-"; 
    node* r = constructTree(postfix);
    inorder(r);
	cout<<endl;
    return 0;
}

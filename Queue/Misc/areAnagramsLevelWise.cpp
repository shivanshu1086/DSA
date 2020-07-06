#include <iostream>
#include <queue>
#include <map>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp=new node();
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

bool areAnagrams(node *root1, node *root2){

    queue<node *> q1,q2;
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty()){
        int count=q1.size();
        int count2=q2.size();
        if(count!=count2){
            return false;
        }
        map<int,int> mp1;
        map<int,int> mp2;
        while(count--){
            node *tmp=q1.front();
            node *tmp2=q2.front();
            q1.pop();
            q2.pop();
            mp1[tmp->data]++;
            mp2[tmp2->data]++;
            if(tmp->left!=NULL){
                q1.push(tmp->left);
            }
            if(tmp2->left!=NULL){
                q2.push(tmp2->left);
            }
            if(tmp->right!=NULL){
                q1.push(tmp->right);
            }
            if(tmp2->right!=NULL){
                q2.push(tmp2->right);
            }
        }

        for(auto it_m1=mp1.cbegin(), end_m1=mp1.cend(), it_m2=mp2.cbegin(), end_m2=mp2.cend();it_m1!=end_m1||it_m2!=end_m2;){
            if(it_m1!=end_m1){
                if(it_m1->second!=it_m2->second){
                    return false;
                }
                ++it_m1;
                ++it_m2;
            }
        }
    }
    return true;
}

int main(){
    node *root1=newNode(1);
    root1->left = newNode(3); 
    root1->right = newNode(2); 
    root1->right->left = newNode(5); 
    root1->right->right = newNode(4);
    root1->left->left = newNode(8);

    node *root2=newNode(1);
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5);
    root2->right->left = newNode(8);

    (areAnagrams(root1,root2))?cout<<"Yes":cout<<"No";
    cout<<endl;
	return 0;
}
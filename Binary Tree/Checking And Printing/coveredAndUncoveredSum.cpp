#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp=new node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

int Sum(node *root, int &ans){
    if(root==NULL){
        return 0;
    }
    else{
        Sum(root->left,ans);
        ans+=root->data;
        Sum(root->right,ans);
    }
    return ans;
}

int UncoveredNodesSum(node *root, int &ans){
    int leftSum = 0, right_sum = 0;
    int final_sum=root->data;
    node *left_part=root->left;
    node *right_part=root->right;

    while(left_part!=NULL){
        leftSum+=left_part->data;
        if(left_part->left==NULL && left_part->right!=NULL){
            left_part=left_part->right;
        }
        else if(left_part->left==NULL && left_part->right==NULL){
            break;
        }
        else{
            left_part=left_part->left;
        }
    }

    while(right_part!=NULL){
        right_sum+=right_part->data;
        if(right_part->right==NULL && right_part->left!=NULL){
            right_part=right_part->left;
        }
        else if(right_part->left==NULL && right_part->right==NULL){
            break;
        }
        else{
            right_part=right_part->right;
        }
    }

    final_sum+=leftSum+right_sum;
    return final_sum;
}

bool isSumSame(node *root){
    int i=0,j=0;
    int all_sum = Sum(root,i);
    int UncoveredSum = UncoveredNodesSum(root,j);
    return ((all_sum-UncoveredSum)==UncoveredSum);
}

int main(){
    node *root = newNode(5);
    root->left = newNode(2); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(9); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(8);
    root->left->left->right = newNode(2);
  
    root->right = newNode(3); 
    root->right->right = newNode(2); 
    root->right->right->left = newNode(12);
    if (isSumSame(root)) 
        printf("Sum of covered and uncovered is same\n"); 
    else
        printf("Sum of covered and uncovered is not same\n");
    cout<<endl;
    return 0;
}
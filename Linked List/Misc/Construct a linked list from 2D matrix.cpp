#include <iostream>
#include <cmath>

using namespace std;

struct Node { 
    int data; 
    Node* right, *down; 
};

Node *construct(int a[][3], int i, int j, int m, int n){
    if(i>n-1 || j>m-1){
        return NULL;
    }

    Node *temp=new Node();
    temp->data=a[i][j];
    temp->right=construct(a,i,j+1,m,n);
    temp->down=construct(a,i+1,j,m,n);
    return temp;
}

void display(Node *head){
    Node *rp;
    Node *dp=head;
    while(dp){
        rp=dp;
        while(rp){
            cout<<rp->data<<" ";
            rp=rp->right;
        }
        cout<<endl;
        dp=dp->down;
    }
}

int main(){
   int arr[][3] = { 
        { 1, 2, 3 }, 
        { 4, 5, 6 }, 
        { 7, 8, 9 } 
    }; 
  
    int m = 3, n = 3; 
    Node* head = construct(arr, 0, 0, m, n); 
    display(head); 
    cout<<endl;
    return 0;
}
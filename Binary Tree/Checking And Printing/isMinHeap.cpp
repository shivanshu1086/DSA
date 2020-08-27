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

bool isMinHeap(int level[], int n){
    for(int i=(n/2-1);i>=0;i--){
        if(level[i]>level[2*i+1]){
            return false;
        }

        if(2*i+2<n){
            if (level[i] > level[2 * i + 2]) 
                return false;
        }
    }
    return true;
}

int main(){
    int level[] = {10, 15, 14, 25, 30}; 
    int n = sizeof(level)/sizeof(level[0]); 
    if  (isMinHeap(level, n)) 
        cout << "True"; 
    else
        cout << "False";
    cout<<endl;
    return 0;
}
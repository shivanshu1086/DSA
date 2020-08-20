#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node { 
    int key; 
    vector<Node*> child; 
}; 

Node* newNode(int value) 
{ 
    Node* nNode = new Node; 
    nNode->key = value; 
    return nNode; 
}

Node *BuildArrTree(int A[], int n, int k, int &ind, int h){
    if(n<=0){
        return NULL;
    }
    Node *nNode = newNode(A[ind]);
    if(nNode==NULL){
        cout<<"Memory error";
        return NULL;
    }

    for(int i=0;i<k;i++){
        if(ind<n-1 && h>1){
            ind++;
            nNode->child.push_back(BuildArrTree(A,n,k,ind,h-1));
        }
        else{
            nNode->child.push_back(NULL);
        }
    }
    return nNode;
}

Node *build_k_Tree(int *preOrder, int n, int k, int s){
    int height = (int)ceil(log((double)n * (k - 1) + 1) / log((double)k));
    return BuildArrTree(preOrder,n,k,s,height);
}

void postord(Node* root, int k) 
{ 
    if (root == NULL) 
        return; 
    for (int i = 0; i < k; i++) 
        postord(root->child[i], k); 
    cout << root->key << " "; 
} 

int main(){
    int n=10,k=3;
    int preorder[] = { 1, 2, 5, 6, 7, 3, 8, 9, 10, 4 };
    Node *root = build_k_Tree(preorder,n,k,0);
    cout << "Postorder traversal of constructed"
             " full k-ary tree is: "; 
    postord(root, k);
    cout<<endl;
    return 0;
}
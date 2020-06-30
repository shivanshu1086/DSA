#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    vector<Node *> child;

    Node(int data){
        this->data=data;
    }
};

int numberOfSiblings(Node *root, int key){
    if(root==NULL){
        return 0;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *tmp=q.front();
        q.pop();

        for(int i=0;i<tmp->child.size();i++){
            if(tmp->child[i]->data==key){
                return tmp->child.size()-1;
            }
            q.push(tmp->child[i]);
        }
    }

    return -1;
}

int main(){
    Node* root = new Node(50); 
    (root->child).push_back(new Node(2)); 
    (root->child).push_back(new Node(30)); 
    (root->child).push_back(new Node(14)); 
    (root->child).push_back(new Node(60)); 
    (root->child[0]->child).push_back(new Node(15)); 
    (root->child[0]->child).push_back(new Node(25)); 
    (root->child[0]->child[1]->child).push_back(new Node(70)); 
    (root->child[0]->child[1]->child).push_back(new Node(100)); 
    (root->child[1]->child).push_back(new Node(6)); 
    (root->child[1]->child).push_back(new Node(1)); 
    (root->child[2]->child).push_back(new Node(7)); 
    (root->child[2]->child[0]->child).push_back(new Node(17)); 
    (root->child[2]->child[0]->child).push_back(new Node(99)); 
    (root->child[2]->child[0]->child).push_back(new Node(27)); 
    (root->child[3]->child).push_back(new Node(16));

    int x=100;
    cout << numberOfSiblings(root, x) << endl;
    cout<<endl;
	return 0;
}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node  
{ 
    int data; 
    Node *left, *right; 
}; 
  
// returns a new 
// tree Node 
Node* newNode(int data) 
{ 
    Node* temp = new Node(); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

int maxSum(vector<int> arr, int n) 
{ 
    // to store the maximum value that is ending 
    // up to the current index 
    int max_ending_here = INT_MIN; 
  
    // to store the maximum value encountered so far 
    int max_so_far = INT_MIN; 
  
    // traverse the array elements 
    for (int i = 0; i < n; i++) { 
  
        // if max_ending_here < 0, then it could 
        // not possibly contribute to the maximum  
        // sum further 
        if (max_ending_here < 0) 
            max_ending_here = arr[i]; 
  
        // else add the value arr[i] to max_ending_here 
        else
            max_ending_here += arr[i]; 
  
        // update max_so_far 
        max_so_far = max(max_so_far, max_ending_here); 
    } 
  
    // required maxium sum contiguous subarray value 
    return max_so_far; 
} 

int maxSpiralSum(Node* root) 
{ 
    // if tree is empty 
    if (root == NULL) 
        return 0; 
  
    // Create two stacks to store alternate levels 
    stack<Node*> s1; // For levels from right to left 
    stack<Node*> s2; // For levels from left to right 
  
    // vector to store spiral order traversal 
    // of the binary tree 
    vector<int> arr; 
  
    // Push first level to first stack 's1' 
    s1.push(root); 
  
    // traversing tree in spiral form until  
    // there are elements in any one of the  
    // stacks 
    while (!s1.empty() || !s2.empty()) { 
  
        // traverse current level from s1 and 
        // push nodes of next level to s2 
        while (!s1.empty()) { 
            Node* temp = s1.top(); 
            s1.pop(); 
  
            // push temp-data to 'arr' 
            arr.push_back(temp->data); 
  
            // Note that right is pushed before left 
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
  
        // traverse current level from s2 and 
        // push nodes of next level to s1 
        while (!s2.empty()) { 
            Node* temp = s2.top(); 
            s2.pop(); 
  
            // push temp-data to 'arr' 
            arr.push_back(temp->data); 
  
            // Note that left is pushed before right 
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
    } 
  
    // required maximum spiral sum 
    return maxSum(arr, arr.size()); 
} 


int main(){
    Node* root = newNode(-2); 
    root->left = newNode(-3); 
    root->right = newNode(4); 
    root->left->left = newNode(5); 
    root->left->right = newNode(1); 
    root->right->left = newNode(-2); 
    root->right->right = newNode(-1); 
    root->left->left->left = newNode(-3); 
    root->right->right->right = newNode(2); 
  
    cout << "Maximum Spiral Sum = "
         << maxSpiralSum(root); 
    cout<<endl;
    return 0;
}
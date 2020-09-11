#include <iostream>
#include <unordered_set>

using namespace std;

struct Node 
{ 
  int data; 
  struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
  /* allocate node */
  struct Node* new_node = 
          (struct Node*) malloc(sizeof(struct Node)); 
   
  /* put in the data  */
  new_node->data  = new_data; 
   
  /* link the old list to the new node */
  new_node->next = (*head_ref); 
   
  /* move the head to point to the new node */
  (*head_ref)    = new_node; 
}

int countPairs(Node *head1, Node *head2, int sum){
    int count = 0; 
      
    unordered_set<int> us;
    while (head1 != NULL) 
    { 
        us.insert(head1->data);     
          
        // move to next node     
        head1 = head1->next; 
    }

    while(head2!=NULL){
        if (us.find(sum - head2->data) != us.end()) 
            count++;
        
        head2 = head2->next;
    }

    return count;
}


int main(){
    struct Node* head1 = NULL; 
    struct Node* head2 = NULL; 
      
    // create linked list1 3->1->5->7 
    push(&head1, 7); 
    push(&head1, 5); 
    push(&head1, 1); 
    push(&head1, 3);     
      
    // create linked list2 8->2->5->3 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 2); 
    push(&head2, 8); 
      
    int x = 10; 
      
    cout << "Count = "
         << countPairs(head1, head2, x);
    cout<<endl;
    return 0;
}
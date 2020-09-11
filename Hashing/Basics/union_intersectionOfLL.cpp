#include <iostream>
#include <unordered_map>

using namespace std;

struct Node { 
    int data; 
    struct Node* next; 
};

void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = (struct Node*)malloc( 
        sizeof(struct Node)); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
}

void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

void storeEle(Node *head1, Node *head2, unordered_map<int,int> &eleOcc){
    struct Node* ptr1 = head1; 
    struct Node* ptr2 = head2;

    while(ptr1!=NULL || ptr2!=NULL){
        if(ptr1!=NULL){
            eleOcc[ptr1->data]++;
            ptr1=ptr1->next;
        }
        if(ptr2!=NULL){
            eleOcc[ptr2->data]++;
            ptr2=ptr2->next;
        }
    }
}

Node *getIntersection(unordered_map<int,int> eleOcc){
    struct Node* result = NULL;
    for(auto i:eleOcc){
        if(i.second==2){
            push(&result,i.first);
        }
    }
    return result;
}

Node *getUnion(unordered_map<int,int> eleOcc){
    struct Node *result = NULL;
    for(auto i:eleOcc){
        push(&result,i.first);
    }
    return result;
}

void printUnionIntersection(Node* head1, 
                            Node* head2) 
{
    unordered_map<int, int> eleOcc;
    storeEle(head1, head2, eleOcc);

    Node* intersection_list = getIntersection(eleOcc);
    Node* union_list = getUnion(eleOcc); 

    printf("\nIntersection list is \n"); 
    printList(intersection_list); 
  
    printf("\nUnion list is \n"); 
    printList(union_list);
}


int main(){
    struct Node* head1 = NULL; 
    struct Node* head2 = NULL;

    push(&head1, 1); 
    push(&head1, 2); 
    push(&head1, 3); 
    push(&head1, 4); 
    push(&head1, 5);

    push(&head2, 1); 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 6);

    printf("First list is \n"); 
    printList(head1); 
  
    printf("\nSecond list is \n"); 
    printList(head2);

    printUnionIntersection(head1, head2);
    cout<<endl;
    return 0;
}
#include <iostream>


using namespace std;
//unrolled linkde list

class unrolledll{
public:
    int numelements;
    int array[4];
    unrolledll *next;
};

void print(unrolledll *n){
    while(n!=NULL){
        for(int i=0;i<n->numelements;i++){
            cout<<n->array[i]<<" ";
        }
        n=n->next;
    }
}


int main(){
    unrolledll *head, *second, *third;
    head=new unrolledll();
    second=new unrolledll();
    third=new unrolledll();

    head->numelements = 3;  
    head->array[0] = 1;  
    head->array[1] = 2;  
    head->array[2] = 3;

    head->next=second;


    second->numelements = 3;  
    second->array[0] = 4;  
    second->array[1] = 5;  
    second->array[2] = 6;

    second->next=third;

    third->numelements = 3;  
    third->array[0] = 7;  
    third->array[1] = 8;  
    third->array[2] = 9;  
    third->next = NULL;

    print(head);
    cout<<endl;
    return 0;
}
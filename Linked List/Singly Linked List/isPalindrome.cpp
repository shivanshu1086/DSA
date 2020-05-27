#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

bool isPalindrome(node *head){
    stack<int> s;
    node *Ptr=head;
    while(Ptr!=NULL){
        s.push(Ptr->data);
        Ptr=Ptr->next;
    }

    node *Ptr2=head;
    while(Ptr2!=NULL){
        int d=s.top();
        s.pop();
        if(d!=Ptr2->data){
            return false;
        }
        Ptr2=Ptr2->next;
    }
    return true;
}

bool palindrome(node *head){
    string s="";
    node *ptr=head;
    while(ptr!=NULL){
        s=s+to_string(ptr->data);
        ptr=ptr->next;
    }
    string s1="";
    for(int i=0;i<s.length();i++){
        s1=s1+s[s.length()-i-1];
    }
    if(s==s1){
        return true;
    }
    return false;
}

int main(){
    linkedlist l;
    // for(int i=1;i<7;i++){
    //     l.insertAtEnd(i);
    // }
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(5);
    l.insertAtEnd(2);
    l.insertAtEnd(1);
    // cout<<boolalpha<<isPalindrome(l.head);
    cout<<boolalpha<<palindrome(l.head);
    // l.print();
    cout<<endl;
    return 0;
}
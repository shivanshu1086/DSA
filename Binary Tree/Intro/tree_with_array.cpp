#include <iostream>

using namespace std;

char tree[10];

int root(char r){
    if(tree[0]!='\0'){
        cout<<"Already root assigned";
    }
    else{
        tree[0]=r;
    }
    return 0;
}

int insert_left(char r, int parent){
    if(tree[parent]=='\0'){
        cout<<"Can't set the child";
    }
    else{
        tree[(parent*2)+1]=r;
    }
    return 0;
}

int insert_right(char r, int parent){
    if(tree[parent]=='\0'){
        cout<<"Can't set the child";
    }
    else{
        tree[(parent*2)+2]=r;
    }
    return 0;
}

void print_tree(){
    cout<<endl;
    for(int i = 0; i < 10; i++) 
    { 
        if(tree[i] != '\0') 
            cout << tree[i]; 
        else
            cout << "-"; 
    } 
}


int main(){
    root('A');
    insert_right('C',0);
    insert_right('D',1);
    insert_left('E',1);
    print_tree();
	cout<<endl;
    return 0;
}

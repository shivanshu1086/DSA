#include <iostream>

using namespace std;

class node{
public:
    int key;
    node **forward;
    node(int,int);
};

node::node(int key, int level){
    this->key=key;
    forward=new node*[level+1];
    memset(forward,0,sizeof(node*)*(level+1));
};


class Skiplist{
    int MaxLvl;
    float P;
    int level;
    node *header;
public:
        Skiplist(int, float);
        int randomlevel();
        node *createNode(int,int);
        void insertElement(int);
        void display();
        void searchElement(int);
        void deleteElement(int);
};

Skiplist::Skiplist(int maxlvl, float P){
    this->MaxLvl=maxlvl;
    this->P=P;
    level=0;

    header = new node(-1,MaxLvl);
};

int Skiplist::randomlevel(){
    float r= (float)rand()/RAND_MAX;
    int lvl=0;
    while(r<P && lvl<MaxLvl){
        lvl++;
        r= (float)rand()/RAND_MAX;
    }
    return lvl;
};

node *Skiplist::createNode(int key, int level){
    node *n = new node(key,level);
    return n;
};

void Skiplist::insertElement(int key){
    node *current=header;

    node *update[MaxLvl+1];
    memset(update,0,sizeof(node*)*(MaxLvl+1));

    for(int i=level;i>=0;i--){
        while(current->forward[i]!=NULL && current->forward[i]->key<key){
            current=current->forward[i];
        }
        update[i]=current;
    }

    //reached the desired position
    current=current->forward[0];

    if(current==NULL || current->key!=key){
        int rlevel=randomlevel();

        if(rlevel>level){
            for(int i=level+1;i<rlevel+1;i++){
                update[i]=header;
            }
            level=rlevel;
        }

        node *n=createNode(key,rlevel);

        for(int i=0;i<=rlevel;i++){
            n->forward[i]=update[i]->forward[i];
            update[i]->forward[i]=n;
        }
        cout<<"Successfully inserted key "<<key<<endl;
    }
};

void Skiplist::searchElement(int key){
    node *current=header;


    //starting from the highest level
    for(int i=level;i>=0;i--){
        while(current->forward[i] && current->forward[i]->key<key){
            current=current->forward[i];
        }
    }

    current=current->forward[0];

    if(current and current->key==key){
        cout<<"Found key: "<<key<<endl;
    }
};


void Skiplist::deleteElement(int key){
    node *current=header;

    node *update[MaxLvl+1];
    memset(update,0,sizeof(node *)*(MaxLvl+1));


    for(int i=level; i>=0;i--){
        while(current->forward[i]!=NULL && current->forward[i]->key<key){
            current=current->forward[i];
        }
        update[i]=current;
    }

    current=current->forward[0];

    if(current!=NULL and current->key==key){
        for(int i=0;i<=level;i++){
            if(update[i]->forward[i]!=current){
                break;
            }
            update[i]->forward[i]=current->forward[i];
        }

        while(level>0 && header->forward[level]==0){
            level--;
        }
        cout<<"Successfully deleted key "<<key<<"\n";
    }
};


void Skiplist::display(){
    cout<<"\n*****Skip List*****"<<"\n"; 
    for(int i=0;i<=level;i++){
        node *Node = header->forward[i];
        cout << "Level " << i << ": ";
        while (Node != NULL){ 
            cout << Node->key<<" "; 
            Node = Node->forward[i]; 
        }
        cout << "\n";
    }
};


int main()
{
    srand((unsigned)time(0));

    Skiplist lst(3,0.5);

    lst.insertElement(3);
    lst.insertElement(6);
    lst.insertElement(7);
    lst.insertElement(9);
    lst.insertElement(12);
    lst.insertElement(19);
    lst.insertElement(17);
    lst.insertElement(26);
    lst.insertElement(21);
    lst.insertElement(25);
    lst.display();
    lst.searchElement(19);
    lst.deleteElement(19);
    lst.display();
    cout<<endl;
    return 0;
}
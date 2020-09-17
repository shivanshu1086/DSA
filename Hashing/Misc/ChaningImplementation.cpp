#include <iostream>
#include <list>
using namespace std;

class Hash{
    int Bucket;
    list<int> *table;
public:
    Hash(int V);
    void insertItem(int x);
    void deleteItem(int key);
    void displayHash();
    int hashFunction(int x){ 
        return (x % Bucket); 
    }
};

Hash::Hash(int V){
    this->Bucket = V;
    table = new list<int>[Bucket];
}

void Hash::insertItem(int x){
    int index = hashFunction(x);
    table[index].push_back(x);
}

void Hash::deleteItem(int key){
    int index = hashFunction(key);
    list <int> :: iterator i;
    for(i=table[index].begin();i!=table[index].end();i++){
        if(*i==key){
            break;
        }
    }
    if(i!=table[index].end()){
        table[index].erase(i);
    }
}

void Hash::displayHash(){
    for(int i=0;i<Bucket;i++){
        cout<<i;
        list <int> :: iterator itr;
        for(itr=table[i].begin();itr!=table[i].end();itr++){
            cout<<"->"<<*itr;
        }
        cout<<endl;
    }
}

int main() {
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 
    
    // insert the keys into the hash table 
    Hash h(37);   // 7 is count of buckets in 
                // hash table 
    for (int i = 0; i < n; i++)  
        h.insertItem(a[i]);   
    
    // delete 12 from hash table 
    h.deleteItem(12); 
    
    // display the Hash table 
    h.displayHash();
    cout<<endl;
	return 0;
}
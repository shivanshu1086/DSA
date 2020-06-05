#include <iostream>
#include <list>

using namespace std;

//STL list


int main(){
    list<int> l,l2;
    int arr[10] = { 1, 2, 3, 4 };
    l.assign(4,2);
    for(auto i:l){
        cout<<i<<" ";
    }
    l2.assign(l.begin(),l.end());//ll assign
    l.assign(arr,arr+10);//array assign

    l.push_front(3);
    l.emplace_front(8);//containerized way for insertion
    //same as inserting from back/end;
    auto i=l.begin();
    l.insert(i,2);//position and number
    cout<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class datastructure{

    vector<int> arr;
    map<int,int> map;
public:

    void add(int x){
        if(map.find(x)!=map.end()){
            return;
        }

        int index = arr.size();
        arr.push_back(x);
        map[x]=index;
    }

    void remove(int x){
        if(map.find(x)==map.end()){
            return;
        }

        int index = map.at(x);
        map.erase(x);

        swap(arr[index],arr[arr.size()-1]);

        arr.pop_back();

        map[arr[index]]=index;
    }

    int search(int x){
        if(map.find(x)!=map.end()){
            return map[x];
        }
        return -1;
    }

    int getRandom(){
        srand (time(NULL));
        int random_index = rand()%arr.size();
        return arr[random_index];
    }
};

int main() {
    datastructure ds;
    ds.add(10); 
    ds.add(20); 
    ds.add(30); 
    ds.add(40); 
    cout << ds.search(30) << endl; 
    ds.remove(20); 
    ds.add(50); 
    cout << ds.search(50) << endl; 
    cout << ds.getRandom() << endl;
    cout<<endl;
	return 0;
}
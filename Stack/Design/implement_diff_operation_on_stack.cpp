#include <iostream>
#include <vector>
#include <climits>

#define MAX 1000
using namespace std;

class Stack{
    int minn;
    int size;
public:
    Stack(){
        minn=INT_MAX;
        size=-1;
    }

    vector<pair<int,int> > arr;

    int addEle(int x){
        if(size>MAX-1){
            cout<<"Stack Overflow";
            return 0;
        }
        if(x<minn){
            minn=x;
        }
        arr.push_back(make_pair(x,minn));
        size++;
        return 1;
    }

    int getLast(){
        if (size == -1) { 
        cout << "No elements in stack\n"; 
        return 0; 
    } 
        return arr[size].first;
    }

    int getMin(){
        if (size == -1) { 
        cout << "stack empty!!\n"; 
        return 0; 
    } 
        return arr[size].second;
    }

    int removeLast(){
        if (size == -1) { 
            cout << "stack empty!!!\n"; 
            return 0; 
        }
        if(size>0 && arr[size-1].second>arr[size].second){
            minn=arr[size-1].second;
        }
        arr.pop_back();
        size-=1;
        return 1;
    }

};

int main() 
{
    Stack s; 
    int success = s.addEle(5); 
    if (success == 1) 
        cout << "5 inserted successfully\n"; 
  
    success = s.addEle(7); 
    if (success == 1) 
        cout << "7 inserted successfully\n"; 
  
    success = s.addEle(3); 
    if (success == 1) 
        cout << "3 inserted successfully\n"; 
    int min1 = s.getMin(); 
    cout << "min element  :: " << min1 << endl; 
  
    success = s.removeLast(); 
    if (success == 1) 
        cout << "removed successfully\n"; 
  
    success = s.addEle(2); 
    if (success == 1) 
        cout << "2 inserted successfully\n"; 
  
    success = s.addEle(9); 
    if (success == 1) 
        cout << "9 inserted successfully\n"; 
    int last = s.getLast(); 
    cout << "Last element :: " << last << endl; 
  
    success = s.addEle(0); 
    if (success == 1) 
        cout << "0 inserted successfully\n"; 
    min1 = s.getMin(); 
    cout << "min element  :: " << min1 << endl; 
  
    success = s.removeLast(); 
    if (success == 1) 
        cout << "removed successfully\n"; 
  
    success = s.addEle(11); 
    if (success == 1) 
        cout << "11 inserted successfully\n"; 
    min1 = s.getMin(); 
    cout << "min element  :: " << min1 << endl; 
    cout<<endl;
	return 0; 
} 

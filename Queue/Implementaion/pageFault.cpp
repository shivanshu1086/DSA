#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int pageFault(int pages[], int capacity, int n){
    unordered_set<int> s;

    queue<int> index;
    int page_fault=0;

    for(int i=0;i<n;i++){
        if(s.size()<capacity){
            s.insert(pages[i]);
            page_fault++;
            index.push(pages[i]);
        }
        else{
            if(s.find(pages[i])==s.end()){
                int val = index.front();
                index.pop();
                s.erase(val);
                s.insert(pages[i]);
                index.push(pages[i]);
                page_fault++;
            }
        }
    }
    return page_fault;
}

int main(){
    int pages[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n=sizeof(pages)/sizeof(pages[0]);
    int capacity=4;
    cout<<pageFault(pages,capacity,n);
    cout<<endl;
	return 0;
}
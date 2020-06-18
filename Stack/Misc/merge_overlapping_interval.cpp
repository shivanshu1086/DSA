#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class pairs{
public:
    int start;
    int end;
};

bool compare(pairs a, pairs b){
    return a.start<b.start;
}

void overlapping_intervals(pairs *interval, int n){
    sort(interval,interval+n,compare);
    stack<pairs> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(interval[i]);
        }
        else{
            if(s.top().end<interval[i].start){
                s.push(interval[i]);
            }
            else if(interval[i].end>s.top().end){
                pairs temp = s.top();
                s.pop();
                pairs merged;
                merged.start=temp.start;
                merged.end=interval[i].end;
                s.push(merged);
            }
        }
    }

    while(!s.empty()){
        cout<<s.top().start<< " "<<s.top().end<<endl;
        s.pop();
    }
}

int main(){
    pairs interval[]={{6,8}, {1,9}, {2,4}, {4,7}};
    int n=sizeof(interval)/sizeof(interval[0]);
    overlapping_intervals(interval,n);
    cout<<endl;
	return 0; 
}
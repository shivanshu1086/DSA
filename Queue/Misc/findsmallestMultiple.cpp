#include <iostream>
#include <queue>
#include <numeric>
#define MAX_COUNT 100000
using namespace std;

vector<string> vec;

void generateNumbers(){
    queue<string> q;

    q.push("9");

    for(int cnt=MAX_COUNT;cnt>0;cnt--){
        string s1=q.front();

        q.pop();

        vec.push_back(s1);

        string s2=s1;
        q.push(s1.append("0"));
        q.push(s2.append("9"));
    }
}

string findsmallestMultiple(int n){
    for(int i=0;i<vec.size();i++){
        if(stoi(vec[i])%n==0){
            return vec[i];
        }
    }
}

int main(){
    generateNumbers();
    int n=7;
    cout<<findsmallestMultiple(n);
    cout<<endl;
	return 0;
}
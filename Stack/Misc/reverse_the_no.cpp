#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

stack<int> s;

void pushing(int n){
    while(n!=0){
        s.push(n%10);
        n=n/10;
    }
}

int reverse(int n){
    pushing(n);

    int reverse=0;
    int i=1;

    while(!s.empty()){
        reverse = reverse + (s.top()*i);
        s.pop();
        i=i*10;
    }
    return reverse;
}

int main() {
    int n=324252;
    cout<<reverse(n);
    cout<<endl;
	return 0;
}
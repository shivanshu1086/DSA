#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool checkStackPermutation(int *input, int *output, int n){
    queue<int> inp;
    queue<int> out;

    for(int i=0;i<n;i++){
        inp.push(input[i]);
        out.push(output[i]);
    }

    stack<int> s;

    while(!inp.empty()){
        int f=inp.front();
        inp.pop();
        if(f==out.front()){
            out.pop();
            while(!s.empty()){
                if(s.top()==out.front()){
                    s.pop();
                    out.pop();
                }
                else{
                    break;
                }
            }
        }
        else{
            s.push(f);
        }
    }

    return (inp.empty()&&s.empty());
}

int main() {
    int input[] = {1, 2, 3};
    int output[] = {2, 1, 3};
    int n=3;
    if (checkStackPermutation(input, output, n))
        cout << "Yes"; 
    else
        cout << "Not Possible";
    cout<<endl;
	return 0;
}
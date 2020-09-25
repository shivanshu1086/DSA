#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct node 
{ 
    int val; 
    int level; 
};

int minOperations(int x, int y) 
{
    set<int> visit;

    queue<node> q; 
    node n = {x, 0}; 
    q.push(n);

    while(!q.empty()){
        node t = q.front(); 
        q.pop();

        if (t.val == y) 
            return t.level;

        visit.insert(t.val);

        // If we can reach y in one more step 
        if (t.val*2 == y || t.val-1 == y) 
            return t.level+1;

        if(visit.find(t.val*2)==visit.end()){//both the allowed operations
            n.val = t.val*2;
            n.level = t.level+1;
            q.push(n);
        }

        if(t.val-1>=0 && visit.find(t.val-1)==visit.end()){
            n.val = t.val-1;
            n.level = t.level+1;
            q.push(n);
        }
    }
    return INT_MAX;
}

int main(){
    int x = 2, y = 5; 
    cout << minOperations(x, y);
    cout<<endl;
    return 0;
}
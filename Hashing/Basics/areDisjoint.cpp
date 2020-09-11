#include <iostream>
#include <set>

using namespace std;

bool areDisjoint(int *a, int *b, int n, int m){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }

    for(int i=0;i<m;i++){
        if(s.find(b[i])!=s.end()){
            return false;
        }
    }
    return true;
}

int main(){
    int set1[] = {10, 5, 3, 4, 6}; 
    int set2[] = {8, 7, 9, 2}; 
  
    int n1 = sizeof(set1) / sizeof(set1[0]); 
    int n2 = sizeof(set2) / sizeof(set2[0]); 
    if (areDisjoint(set1, set2, n1, n2)) 
        cout << "Yes"; 
    else
        cout << "No";
    cout<<endl;
    return 0;
}
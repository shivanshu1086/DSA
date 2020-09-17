#include <iostream>
#include <unordered_set>
using namespace std;


void recaman(int n) 
{
    if (n <= 0) 
      return;
    printf("%d, ", 0);
    unordered_set<int> s;
    s.insert(0);

    int prev = 0;
    for(int i=1;i<n;i++){
        int curr = prev-i;

        if(curr<0 || s.find(curr)!=s.end()){
            curr = prev+i;
        }

        s.insert(curr);

        printf("%d, ", curr); 
        prev = curr;
    }

}

int main() {
    int n = 17; 
    recaman(n);
    cout<<endl;
	return 0;
}
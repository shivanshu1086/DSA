#include <iostream>
#include <cmath>
using namespace std;

int sumNodes(int l){
    int noOfLeaf = pow(2,l-1);

    int sumOfLeaf = (noOfLeaf*(noOfLeaf+1))/2;

    return sumOfLeaf*l;
}


int main(){
    // node *root = newNode(1);
    int l=3;
    cout << sumNodes(l);
    cout<<endl;
    return 0;
}
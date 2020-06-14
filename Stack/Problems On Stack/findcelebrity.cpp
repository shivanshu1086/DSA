#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define N 4
using namespace std;

bool matrix[N][N]={{0,0,1,0},
                   {0,0,1,0},
                   {0,0,0,0},
                   {0,0,1,0}};

bool knows(int a, int b){
    return matrix[a][b];
}

int findcelebrity(int n){
    int a=0;
    for(int i=1;i<n;i++){
        if(knows(a,i)){
            a=i;
        }
    }
    for(int i=0;i<n;i++){
        if((i!=a) && ((knows(a,i))||(!knows(i,a)))){
            return -1;
        }
    }
    return a;
}


int main() 
{
    int n=4;
    int id =findcelebrity(n);
    id==-1?cout<<"No celebrity here":cout<<"celebrity id: "<<id;
    cout<<endl;
	return 0; 
}
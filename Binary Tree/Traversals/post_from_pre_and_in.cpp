#include <iostream>
#include <map>

using namespace std;

int preIndex=0;

void print_order(int in[], int pre[], int inStrt, int inEnd, map<int,int> mp){
    if(inStrt>inEnd){
        return;
    }

    int inIndex = mp[pre[preIndex++]];

    print_order(in,pre,inStrt,inIndex-1,mp);
    print_order(in,pre,inIndex+1,inEnd,mp);
    cout<<in[inIndex]<<" ";
}

void post_order(int in[], int pre[], int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    print_order(in, pre, 0, n-1, mp);
}

int main(){
    int in[]={4, 2, 5, 1, 3, 6};
    int pre[]={1, 2, 4, 5, 3, 6};
    int n=sizeof(in)/sizeof(in[0]);
    post_order(in,pre,n);
	cout<<endl;
    return 0;
}

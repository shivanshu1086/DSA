#include <iostream>
#include <queue>

using namespace std;

bool isChangable(int a[], int n){
    int fiveNote=0;
    int tenNote=0;

    for(int i=0;i<n;i++){
        if(a[i]==5){
            fiveNote++;
        }
        else if(a[i]==10){
            if(fiveNote>0){
                fiveNote--;
                tenNote++;
            }
            else{
                return false;
            }
        }
        else{
            if(fiveNote>0 && tenNote>0){
                fiveNote--;
                tenNote--;
            }
            else if(fiveNote>=3){
                fiveNote-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    int a[]={5,5,5,10,20};
    int n=sizeof(a)/sizeof(a[0]);
    (isChangable(a,n))?cout<<"Yes":cout<<"No";
    cout<<endl;
	return 0;
}
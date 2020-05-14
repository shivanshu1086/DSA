#include <iostream>
#include<vector>
using namespace std;

int min_steps_for_desired_array(int *a, int n){
    int result=0;
    while(1){
        int zeros_counter=0;
        int i;
        for(i=0;i<n;i++){
            if(a[i]&1){//if it is odd element
                break;
            }
            else if(a[i]==0){
                zeros_counter++;
            }
        }//after this loop all zeroes will get counted
        if(zeros_counter==n){
            return result;
        }
        //if all numbers are even
        if(i==n){
            for(int j=0;j<n;j++){
                a[j]/=2;
            }
            result++;
        }
        //odd elements
        for(int j=i;j<n;j++){
            if(a[j]&1){
                a[j]--;
                result++;
            }
        }
    }
}


int main()
{
    int a[]={3, 16, 16};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<min_steps_for_desired_array(a,n);
	cout<<endl;
    return 0;
}

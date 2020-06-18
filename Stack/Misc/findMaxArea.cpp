#include <iostream>
#include <stack>

using namespace std;

int findMaxArea(int *bars, int n){
    stack<int> s;
    int max_area=0;
    int top;
    int max_with_top;
    int i=0;
    while(i<n){
        if(s.empty() || bars[s.top()]<=bars[i]){
            s.push(i++);
        }
        else{
            // A bar is popped from stack when a bar of smaller height is seen. 
            //When a bar is popped, we calculate the area with the popped bar as smallest bar. 
            //How do we get left and right indexes of the popped bar – 
            //the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’.
            top=s.top();
            s.pop();
            max_with_top = bars[top] * (s.empty() ? i : i-s.top()-1);//right-left-1;

            if(max_area<max_with_top){
                max_area=max_with_top;
            }
        }
    }

    while(!s.empty()){
        top=s.top();
        s.pop();
        max_with_top = bars[top] * (s.empty() ? i : i-s.top()-1);

        if(max_area<max_with_top){
            max_area=max_with_top;
        }
    }
    return max_area;
}

int main(){
    int bars[]={6,2,5,4,5,1,6};
    int n=sizeof(bars)/sizeof(bars[0]);
    cout<<"Max area "<<findMaxArea(bars,n);
    cout<<endl;
	return 0; 
}
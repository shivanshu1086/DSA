#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int minimize_the_absolute_diff(int *a, int *b, int *c, int i, int j, int k){
    int min_diff, curr_diff, max_term;
    min_diff=INT_MAX;
    while(i!=-1 && j!=-1 && k!=-1){
        curr_diff=abs(max(a[i],max(b[j],c[k]))-min(a[i],min(b[j],c[k])));

        if(curr_diff<min_diff){
            min_diff=curr_diff;
        }

        max_term=max(a[i],max(b[j],c[k]));
        if (a[i] == max_term) 
            i -= 1; 
        else if (b[j] == max_term) 
            j -= 1; 
        else
            k -= 1; 
    }
    return min_diff;
}

int main()
{
    int D[] = { 5, 8, 10, 15 }; 
    int E[] = { 6, 9, 15, 78, 89 }; 
    int F[] = { 2, 3, 6, 6, 8, 8, 10 }; 
    int nD = sizeof(D) / sizeof(D[0]); 
    int nE = sizeof(E) / sizeof(E[0]); 
    int nF = sizeof(F) / sizeof(F[0]); 
    cout << minimize_the_absolute_diff(D, E, F, nD-1, nE-1, nF-1);
	cout<<endl;
    return 0;
}

#include <iostream>
#include<vector>
using namespace std;

void subsets_of_product_less_than_k(long long int *a, int n, long long int k){
    //four vectors 2 for dividing the array into two halves and 2 for storing the accepted pairs
    vector<long long int> vect1,vect2,subset1,subset2;
    //ignore the elements greater than k and divide the array
    for(int i=0;i<n;i++){
        if(a[i]>k){
            continue;
        }
        if(i<=n/2){
            vect1.push_back(a[i]);
        }
        else{
            vect2.push_back(a[i]);
        }
    }
    //subset generation for (vect1)
    for(int i=0;i<(1<<vect1.size());i++){
        long long value=1;
        for(int j=0;j<vect1.size();j++){
            if(i&(1<<j)){
                value*=vect1[j];
            }
        }
        //push only if it is less than k
        if(value<=k){
            subset1.push_back(value);
        }
    }

    //subset generation for (vect2)
    for(int i=0;i<(1<<vect2.size());i++){
        long long value=1;
        for(int j=0;j<vect2.size();j++){
            if(i&(1<<j)){
                value*=vect2[j];
            }
        }
        //push only if it is less than k
        if(value<=k){
            subset2.push_back(value);
        }
    }
    //sorting the subset2
    sort(subset2.begin(),subset2.end());

    //counting 
    long long count=0;
    for(int i=0;i<subset1.size();i++){
        count+=upper_bound(subset2.begin(),subset2.end(),(k/subset1[i]))-subset2.begin();
    }
    //null set
    count--;
    if(count==0){
        cout<<"1";
    }
    else{
        cout<<count;
    }
}

int main()
{
    long long int a[]={ 4, 2, 3, 6, 5 };
    int n=sizeof(a)/sizeof(a[0]);
    long long int k=25;
    subsets_of_product_less_than_k(a,n,k);
	cout<<endl;
    return 0;
}

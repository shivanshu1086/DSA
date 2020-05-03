#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void pos_neg(int *a, int n){
	vector<int> pos;
	vector<int>neg;
	for(int i=0;i<n;i++){
		if(a[i]<0){
			neg.push_back(a[i]);
		}
		else{
			pos.push_back(a[i]);
		}
	}
	int p=0;
	int ne=0;
	int i=0,j=1;
	// for(int i=0;i<n;i++){
	// 	if(i%2==0 && p<pos.size()){
	// 		a[i]=pos[p];
	// 		p++;
	// 	}
	// 	else if(i%2!=0 && ne<neg.size()){
	// 		a[i]=neg[ne];
	// 		ne++;
	// 	}
	// }
	while(p<pos.size() && ne<neg.size()){
		a[i]=pos[p];
		a[j]=neg[ne];
		p++,ne++,i+=2,j+=2;
	}
	if(ne>=neg.size()){
		for(int k=i;k<n;k++){
			a[k]=pos[p];
			p++;
		}
	}
	else{
		for(int k=i;k<n;k++){
			a[k]=neg[ne];
			ne++;
		}
	}
}


int main() 
{
	int a[]={9, 4, -2, -1, 5, 0, -5, -3 ,2};
	int n=sizeof(a)/sizeof(int);
	pos_neg(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}

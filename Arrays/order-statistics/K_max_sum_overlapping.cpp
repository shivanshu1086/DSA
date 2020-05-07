#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int k_th_largest_sum(int *a, int n, int k){
	int sum[n+1];
	sum[0]=0;
	sum[1]=a[0];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i-1];
	}
	//priority queue of min-heap
	priority_queue<int, vector<int>, greater<int> > mp;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=sum[j]-sum[i-1];
			if(mp.size()<k){
				mp.push(x);
			}
			else{
				if(mp.top()<x){
					mp.pop();
					mp.push(x);
				}
			}
		}
	}
	return mp.top();
}

//alternative method

vector<int> prefix_sum(int *a, int n){
	vector<int> pre_sum;
	pre_sum.push_back(a[0]);
	for(int i=1;i<n;i++){
		pre_sum.push_back(pre_sum[i-1]+a[i]);
	}
	return pre_sum;
}

void maxMerge(vector<int> &maxi, vector<int> cand){
	int k = maxi.size(); 
    int j = 0; 
    for (int i = 0; i < k; i++) { 
        if (cand[j] > maxi[i]) { 
            maxi.insert(maxi.begin() + i, cand[j]); 
            maxi.erase(maxi.begin() + k); 
            j += 1; 
        } 
    }
}

void insertMini(vector<int> &mini, int pre_sum){
	int k = mini.size(); 
    for (int i = 0; i < k; i++) { 
        if (pre_sum < mini[i]) { 
            mini.insert(mini.begin() + i, pre_sum); 
            mini.erase(mini.begin() + k); 
            break; 
        } 
    }
}

void kmaxsums(int *a, int n, int k){
	vector<int> pre_sum = prefix_sum(a,n);

	vector<int> mini(k,numeric_limits<int>::max());
	mini[0]=0;

	vector<int> maxi(k,numeric_limits<int>::min());
	
	vector<int> cand(k);

	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(pre_sum[i] < 0 && mini[j]==numeric_limits<int>::max()){
				cand[j]=(-pre_sum[i])-mini[j];
			}
			else{
				cand[j]=pre_sum[i]-mini[j];
			}
		}
		maxMerge(maxi, cand); 
        insertMini(mini, pre_sum[i]);
	}
	for(int i:maxi){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main() 
{
	int a[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
	int n=sizeof(a)/sizeof(a[0]);
	// for(int i=1;i<=4;i++)
	// cout<<k_th_largest_sum(a,n,i)<<" ";
	kmaxsums(a,n,3);
	cout<<endl;
    return 0;
}

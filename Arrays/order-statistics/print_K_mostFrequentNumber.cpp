#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <queue>
#include<vector>
using namespace std;

bool compar(pair<int, int> p1, pair<int, int> p2){
	if(p1.second==p2.second)
	return p1.first>p2.second;

	return p1.second>p2.second;
}

void print_K_mostFrequentNumber(int *a, int n, int k){
	unordered_map<int,int> um;
	for (int i = 0; i<n; i++) 
        um[a[i]]++;
	
	vector<pair<int,int> > freq_array(um.begin(),um.end());
	sort(freq_array.begin(),freq_array.end(), compar);

	for (int i = 0; i<k; i++) 
        cout << freq_array[i].first << " ";
}//One approach

struct compare{
	bool operator()(pair<int, int> p1, pair<int, int> p2) 
    { 
        if (p1.second == p2.second) 
            return p1.first < p2.first; 
        return p1.second < p2.second;     
    }
};

void print_K_mostFrequentNumber2(int *a, int n, int k){
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		m[a[i]]++;
	}
	// vector<pair<int, int> > freq_arr(m.begin(), m.end());
	priority_queue<pair<int,int>, vector<pair<int,int> >, compare > pq(m.begin(),m.end());
	for (int i = 1; i<= k; i++) 
    { 
        cout << pq.top().first << " "; 
        pq.pop(); 
    } 

}

int main() 
{
	int a[]={3, 1, 4, 4, 5, 2, 6, 1};
	int n=sizeof(a)/sizeof(a[0]);
	// for(auto i:um){
	// 	cout<<i.first<<","<<i.second<<endl;
	// }
	print_K_mostFrequentNumber2(a,n,2);
	cout<<endl;
    return 0;
}

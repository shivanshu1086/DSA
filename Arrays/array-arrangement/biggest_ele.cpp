#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int mycompare(string X, string Y){
		string XY=X.append(Y);
		string YX=Y.append(X);
		return XY.compare(YX) > 0 ? 1 : 0;
	}

void biggest(vector<string>a){
	sort(a.begin(),a.end(),mycompare);
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
}

int main() 
{
	// int a[]={ -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	// int n=sizeof(a)/sizeof(int);
	vector<string> a;
	a.push_back("54");
	a.push_back("546");
	a.push_back("548");
	a.push_back("60");
	biggest(a);
	cout<<endl;
    return 0;
}

//choose an pivot for that next element to it is smaller than it.(wo element apne next se bada hona chahiye)
//pivot is to check if array is rotated or not.if yes then by how value it is rotated.

#include <iostream>
#include<string>
using namespace std;

int binary_search(int *a, int low, int high, int key){
	if(high<low){
		return -1;
	}
	int mid=(low+high)/2;
	if(a[low]==key){
		return low;
	}
	if(a[high]==key){
		return high;
	}
	if(a[mid]==key){
		return mid;
	}
	if(key>a[mid]){
		return binary_search(a,mid+1,high,key);
	}
	return binary_search(a,low,mid-1,key);
}

int findpivot(int *a, int low, int high){
	if(high<low){
		return -1;
	}
	if(high==low){
		return low;//or high anything
	}
	int mid=(low+high)/2;
	if(mid<high && a[mid]>a[mid+1]){
		return mid;
	}
	if(mid>low && a[mid]<a[mid-1]){
		return mid-1;
	}
	if(a[low]>=a[mid]){
		return findpivot(a,low,mid-1);
	}
	return findpivot(a,mid+1,high);
}

int index_rotation_search(int *a, int n, int key){
	int pivot=findpivot(a,0,n-1);
	//if the array is not rotated.
	if(pivot==-1){
		return binary_search(a,0,n-1,key);
	}
	if(a[pivot]==key){
		return pivot;
	}
	if(a[0]<=key){
		return binary_search(a,0,pivot-1,key);
	}
	return binary_search(a,pivot+1,n-1,key);
}

int search(int *a, int l, int h, int key){
	if(l>h){
		return -1;
	}
	int mid=(l+h)/2;
	if(a[mid]==key){
		return mid;
	}
	if(a[l]<=a[mid]){
		if(key>=a[l] && key<=a[mid]){//left me search
			return search(a,l,mid-1,key);
		}
		return search(a,mid+1,h,key);//right me search
	}
	if (key >= a[mid] && key <= a[h]){
		return search(a, mid+1, h, key);//right
	}
     return search(a,l,mid-1,key);    
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key;
	cin>>key;
    int pos=index_rotation_search(a,n,key);
	// int pos2=search(a,0,n-1,key);
	// if(pos!=-1){
	//     cout<<"Index is : "<<index_rotation_search(a,n,key)+1;
    // }
    // else{
    //     cout<<"Index is : "<<index_rotation_search(a,n,key);
    // }
	// cout<<endl<<endl;
    if(pos!=-1){
	    cout<<"Index is : "<<index_rotation_search(a,n,key)+1;
    }
    else{
        cout<<"Index is : "<<index_rotation_search(a,n,key);
    }
	// for(int i=0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
    return 0;
}


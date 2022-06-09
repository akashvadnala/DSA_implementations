#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> arr,int x){
	for(int i=0;i<arr.size();i++)
		if(arr[i]==x) return i;
	return -1;
}

int binary_search(vector<int> arr,int x){
	sort(arr.begin(),arr.end());
	// 1,2,3,5,6,8,10,11,13,17
	int l=0,r=arr.size()-1;
	while(l<=r){
		int m=(l+r)/2;
		if(arr[m]==x) return m;
		else if(arr[m]<x) l=m+1;
		else r=m-1;
	}
	return -1;
}

int jump_search(vector<int> arr,int x){
	sort(arr.begin(),arr.end());
	int n=arr.size();
	int step=sqrt(n);
	int prev=0;
	while(arr[min(n,step)-1]<x){
		prev=step;
		step+=sqrt(n);
		if(prev>=n) return -1;
	}
	while(arr[prev]<x){
		prev++;
		if(prev==min(step,n)) return -1;
	}
	if(arr[prev]==x) return prev;
	return -1;
}

int interpolation_search(vector<int> arr,int x){
	sort(arr.begin(),arr.end());
	int l=0,r=arr.size()-1;
	while(l<=r && arr[l]<=x && x<=arr[r]){
		int pos=l+((double)(r-l)/(arr[r]-arr[l]))*(x-arr[l]);
		if(arr[pos]==x) return pos;
		else if(arr[pos]<x) l=pos+1;
		else r=pos-1;
	} 
	return -1;
}

int exponential_search(vector<int> arr,int x){
	sort(arr.begin(),arr.end());
	if(arr[0]==x) return 0;
	int i=1;
	int n=arr.size();
	while(i<n && arr[i]<=x)
		i*=2;
	int l=i/2,r=min(i,n-1);
	while(l<=r){
		int m=(l+r)/2;
		if(arr[m]==x) return m;
		else if(arr[m]<x) l=m+1;
		else r=m-1;
	}
	return -1;
}


int main(){
	vector<int> arr{1,2,8,3,6,5,11,10,13,17};
	cout<<linear_search(arr,3)<<endl;
	cout<<binary_search(arr,3)<<endl;
	cout<<jump_search(arr,3)<<endl;
	cout<<interpolation_search(arr,3)<<endl;
	cout<<exponential_search(arr,3)<<endl;

}
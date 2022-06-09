#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<int>& arr){
	if(i>j) return 0;
	int mx=INT_MIN;
	for(int ind=i;ind<=j;ind++){
		int cost=arr[i-1]*arr[ind]*arr[j+1]+f(i,ind-1,arr)+f(ind+1,j,arr);
		if(mx<cost) mx=cost;
	}
	return mx;
}

int main(){
	vector<int> arr{3,1,8,5};
	int n=arr.size();
	arr.push_back(1);
	arr.insert(arr.begin(),1);
	return f(1,n,arr);
}
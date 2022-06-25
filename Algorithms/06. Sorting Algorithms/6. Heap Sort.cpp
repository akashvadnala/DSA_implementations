#include <bits/stdc++.h>
using namespace std;

void swap(int& a,int& b){
	int c=a;
	a=b;
	b=c;
}

int main(){
	vector<int> arr{2,3,1,5,8,6,9,4,7};
	int n=arr.size();
	vector<int> heap(n);
	for(int i=0;i<n;i++){
		heap[i]=arr[i];
		int child=i,parent=(child-1)/2;
		while(parent>=0 && heap[parent]<heap[child]){
			swap(heap[child],heap[parent]);
			child=parent;
			parent=(child-1)/2;
		}
	}
	for(auto& i:heap) cout<<i<<' ';
	cout<<endl;
	int r=n-1;
	int mx,i;
	while(r>0){
		swap(heap[0],heap[r]);
		mx=0;
		i=-1;
		while(i!=mx && mx<r){
			i=mx;
			if(2*i+1<r && heap[mx]<heap[2*i+1])
				mx=2*i+1;
			if(2*i+2<r && heap[mx]<heap[2*i+2])
				mx=2*i+2;
			if(i!=mx){
				swap(heap[i],heap[mx]);
			}
		}
		r--;
	}
	for(auto& i:heap) cout<<i<<' ';
}


// time complexity: O(nlogn)
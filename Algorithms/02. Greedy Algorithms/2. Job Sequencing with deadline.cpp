#include <bits/stdc++.h>
using namespace std;

// int jobSequencing(vector<int> profit,vector<int> deadline){
// 	int n=*max_element(deadline.begin(),deadline.end());
// 	vector<int> arr(n,0);
// 	int ans=0;
// 	for(int i=0;i<profit.size();i++){
// 		int j=deadline[i]-1,mn=j;
// 		while(j>=0){
// 			if(arr[j]<=arr[mn]) mn=j;
// 			j--;
// 		}
// 		if(arr[mn]<profit[i]) arr[mn]=profit[i]; 
// 	}
// 	for(auto i:arr) cout<<i<<' ';
// 	ans=accumulate(arr.begin(),arr.end(),0);
// 	return ans;
// } //time complexity:o(n^2)

int jobSequencing(vector<int> profit,vector<int> deadline){
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<profit.size();i++){
		if(pq.size()<deadline[i])
			pq.push(profit[i]);
		else if(pq.top()<profit[i]){
			pq.pop();
			pq.push(profit[i]);
		}
	}
	int ans=0;
	while(!pq.empty()){
		ans+=pq.top();
		pq.pop();
	}
	return ans;
}  //time complexity:O(nlogn)



int main(){
	vector<int> profit{100,19,27,25,15};
	vector<int> deadline{2,1,2,1,3};
	cout<<jobSequencing(profit,deadline)<<endl;
	return 0;
}

//time complexity: O(n^2)
// #include <bits/stdc++.h>
// using namespace std;

// int f(int i,int j,vector<int>& arr){
// 	if(i>j) return 0;
// 	int mn=INT_MAX;
// 	int cost;
// 	for(int ind=i;ind<=j;ind++){
// 		cost=(arr[j+1]-arr[i-1])+f(i,ind-1,arr)+f(ind+1,j,arr);
// 		if(cost<mn) mn=cost;
// 	}
// 	return mn==INT_MAX?0:mn;
// }

// int main(){
// 	int n=7;
// 	vector<int> arr{1,3,4,5};
// 	int c=arr.size();
// 	arr.insert(arr.begin(),0);
// 	arr.push_back(n);
// 	cout<<f(1,c,arr)<<endl;
// 	return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
// 	if(i>j) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int mn=INT_MAX;
// 	int cost;
// 	for(int ind=i;ind<=j;ind++){
// 		cost=(arr[j+1]-arr[i-1])+f(i,ind-1,arr,dp)+f(ind+1,j,arr,dp);
// 		if(cost<mn) mn=cost;
// 	}
// 	return dp[i][j]=mn==INT_MAX?0:mn;
// }

// int main(){
// 	int n=7;
// 	vector<int> arr{1,3,4,5};
// 	int c=arr.size();
// 	arr.insert(arr.begin(),0);
// 	arr.push_back(n);
// 	vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
// 	cout<<f(1,c,arr,dp)<<endl;
// 	for(auto& i:dp){
// 		for(auto& j:i) cout<<j<<' ';
// 			cout<<endl;
// 	}
// 	return 0;
// }




#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=7;
	vector<int> arr{1,3,4,5};
	int c=arr.size();
	arr.insert(arr.begin(),0);
	arr.push_back(n);
	vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
	for(int i=0;i<c;i++){
		for(int j=1;i+j<=c;j++){
			if(i==0) dp[j][j]=arr[j+1]-arr[j-1];
			else if(dp[j][i+j-1]>dp[j+1][i+j]) dp[j][i+j]=dp[j+1][i+j]+arr[i+j+1]-arr[j];
			else if(dp[j][i+j-1]<dp[j+1][i+j])dp[j][i+j]=dp[j][i+j-1]+arr[i+j]-arr[j-1];
			else dp[j][i+j]=dp[j][i+j-1]+min(arr[i+j+1]-arr[j],arr[i+j]-arr[j-1]);
		}
	}
	cout<<dp[1][c]<<endl;
	for(auto& i:dp){
		for(auto& j:i) cout<<j<<' ';
			cout<<endl;
	}
	return 0;
}
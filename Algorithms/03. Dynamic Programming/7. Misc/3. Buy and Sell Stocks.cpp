#include <bits/stdc++.h>
using namespace std;



int f(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
	if(i==prices.size() || cap==0) return dp[i][buy][cap]=0;
	if(dp[i][buy][cap]>0) return dp[i][buy][cap];
	if(buy==1) return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,cap,prices,dp),f(i+1,1,cap,prices,dp));
	return dp[i][buy][cap]=max(prices[i]+f(i+1,1,cap-1,prices,dp),f(i+1,0,cap,prices,dp));
}

int main(){
	vector<int> prices{3,3,5,0,0,3,1,4};
	vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
	return f(0,1,2,prices,dp);
}
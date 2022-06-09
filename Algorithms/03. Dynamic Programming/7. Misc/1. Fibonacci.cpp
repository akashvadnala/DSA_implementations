#include <bits/stdc++.h>
using namespace std;

int fibonacci_recurrsion(int n){
	if(n<=1) return n;
	return fibonacci_recurrsion(n-1)+fibonacci_recurrsion(n-2);
}

vector<int> lookup(100,-1);
int fibonacci_memoization(int n){
	if(lookup[n]==-1){
		if(n<=1) 
			lookup[n]=n;
		else 
			lookup[n]=fibonacci_memoization(n-1)+fibonacci_memoization(n-2);
	}
	return lookup[n];
}

int fibonacci_dynamic(int n){
	int dp[n+1];
	if(n>=0) dp[0]=0;
	if(n>=1) dp[1]=1;
	for(int i=2;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}

int main(){
	int n=9;
	cout<<fibonacci_recurrsion(n)<<endl;
	cout<<fibonacci_memoization(n)<<endl;
	cout<<fibonacci_dynamic(n)<<endl;
}
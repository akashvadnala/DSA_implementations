#include <bits/stdc++.h>
using namespace std;

int rodcutting(vector<int>& price){
    int n=price.size();
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i<=n; ++i){
        int max_val = INT_MIN;
        for(int j = 0; j<i; j++)
            max_val = max(max_val, price[j]+dp[i-j-1]);
        dp[i] = max_val;
    }
    for(int i=0;i<=n;i++) cout<<dp[i]<<' ';
    cout<<endl;
    return dp[n];
}

int main(){
    vector<int> prices{1,2,1,3,2};
    cout<<rodcutting(prices);
    return 0;
}
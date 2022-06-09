#include <bits/stdc++.h>
using namespace std;

int change(vector<int>& coins,int amount) {
    int dp[amount+1];
    dp[0]=1;
    for(int i=1;i<=amount;i++) dp[i]=0;
    for(int coin:coins){
        for(int i=coin;i<=amount;i++)
            dp[i]+=dp[i-coin];
    }
    for(int i=0;i<=amount;i++) cout<<dp[i]<<' '; cout<<endl;
    return dp[amount];
}

int main(){
    vector<int> coins{1,2,5,10};
    int amount=15;
    cout<<change(coins,amount);
    return 0;
}
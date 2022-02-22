class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++) dp[i]=INT_MAX;
        int val;
        for(int i=1;i<=amount;i++){
            val=INT_MAX;
            for(int coin:coins){
                if(i>=coin && dp[i-coin]!=INT_MAX) val=min(val,dp[i-coin]+1);
            }
            dp[i]=val;
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};
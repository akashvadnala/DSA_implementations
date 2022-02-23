class Solution{
public:
    bool isSubset(vector<int>& nums,int& target){
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<dp.size();i++) dp[i][0]=1;
        for(int i = 1; i < dp.size();i++) {
            for(int j = 1;j < dp[0].size();j++) {
                if(j >= nums[i-1]) dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};

// To know whether there is subset with given sum target
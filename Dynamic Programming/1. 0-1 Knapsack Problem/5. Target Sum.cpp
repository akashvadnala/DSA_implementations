class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {         
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(S>sum || (sum-S)%2!=0)
            return 0;
        vector<vector<int>> dp(nums.size()+1,(vector<int>(((sum-S)/2)+1,0))); 
        int c=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                c++;
        for(int i=0;i<nums.size()+1;i++)
            dp[i][0]=1;    
        for(int i=1;i<nums.size()+1;i++)
            for(int j=1;j<((sum-S)/2)+1;j++){
                if(nums[i-1]==0)
                    dp[i][j] = dp[i-1][j];
                else
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return pow(2,c)*dp[nums.size()][(sum-S)/2];
    }
};
class Solution{
    // bool knapsack(vector<int>& nums,int i,int target){
    //     if(target==0) return true;
    //     if(i>=nums.size()) return false;
    //     if(knapsack(nums,i+1,target-nums[i])) return true;
    //     if(knapsack(nums,i+1,target)) return true;
    //     return false;
    // }
    // bool solve(vector<int> &nums, int pos, int sum, vector<int> &dp){
    //     if (sum == 0) return true;
    //     if (sum < 0) return false;
    //     if (dp[sum] != -1) return dp[sum] == 1;
    //     const int n = nums.size();
    //     for (int i = pos; i < n; ++i){
    //         if (solve(nums, i + 1, sum - nums[i], dp)){
    //             dp[sum] = 1;
    //             return true;
    //         }
    //     }
    //     dp[sum] = 0;
    //     return false;
    // }
public:
    bool isSubset(vector<int>& nums,int& target){
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<dp.size();i++) dp[i][0]=1;
        for(int i = 0; i < dp.size();i++) {
            for(int j = 0;j < dp[0].size();j++) {
                if(j >= nums[i-1]) dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
        
        //return knapsack(nums,0,target);
        // int n=nums.size();
        // vector<int> dp(n+1,-1);
        // return solve(nums,0,target,dp);
    }
};
class Solution{
    // bool knapsack(vector<int>& nums,int i,int target){
    //     if(target==0) return true;
    //     if(i>=nums.size()) return false;
    //     if(knapsack(nums,i+1,target-nums[i])) return true;
    //     if(knapsack(nums,i+1,target)) return true;
    //     return false;
    // }
public:
    bool isSubset(vector<int>& nums,int& target){
        //return knapsack(nums,0,target);
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1));
        for(int i = 0; i < dp.size();i++) {
            for(int j = 0;j < dp[0].size();j++) {
                if(i == 0 && j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i-1][j];
                    if(j >= nums[i-1]) {
                        if(dp[i-1][j-nums[i-1]] == true) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[n][target];
    }
};
class Solution {
public:
    bool solve(vector<int> &nums, int pos, int sum, vector<int> &dp){
        if (sum == 0) return true;
        if (sum < 0) return false;
        if (dp[sum] != -1) return dp[sum] == 1;
        const int n = nums.size();
        for (int i = pos; i < n; ++i){
            if (solve(nums, i + 1, sum - nums[i], dp)){
                dp[sum] = 1;
                return true;
            }
        }
        dp[sum] = 0;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<int> dp(sum + 1, -1);
        bool t=solve(nums, 0, sum, dp);
        return t;
    }
};
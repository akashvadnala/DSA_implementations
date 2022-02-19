class Solution{
    bool knapsack(vector<int>& nums,int i,int target){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(knapsack(nums,i+1,target-nums[i])) return true;
        if(knapsack(nums,i+1,target)) return true;
        return false;
    }
public:
    bool isSubset(vector<int>& nums,int& target){
        return knapsack(nums,0,target);
    }
};
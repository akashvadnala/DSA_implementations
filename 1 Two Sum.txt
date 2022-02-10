class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m[target-nums[i]]>0){
                v.push_back(m[target-nums[i]]-1);
                v.push_back(i);
            }
            else
                m[nums[i]]=i+1;
        }
        return v;
    }
};

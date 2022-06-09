class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int mx=nums[0];
        int mn=nums[0];
        for(int i=1;i<nums.size();i++){
            const int pmx=mx;
            const int pmn=mn;
            if(nums[i]>0){
                mx=max(pmx*nums[i],nums[i]);
                mn=min(pmn*nums[i],nums[i]);
            }
            else{
                mx=max(pmn*nums[i],nums[i]);
                mn=min(pmx*nums[i],nums[i]);
            }
            ans=max(ans,mx);
        }
        return ans;
    }
};

// array=[-2,2,3,-4,-6]

//         -2   2   3   -4  -6
//    mn = -2   -4  -12 -24 -288
//    mx = -2   2   6   48  144
//   ans = -2   2   6   48  144
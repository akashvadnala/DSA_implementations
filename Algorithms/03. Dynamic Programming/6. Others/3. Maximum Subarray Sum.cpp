class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=INT_MIN;
        for(int& i:nums){
            sum+=i;
            if(sum<i) sum=i;
            if(ans<sum) ans=sum;
        }
        return ans;
    }
};

//array = [-2,1,-3,4,-1,2,1,-5,4]

//       -2  1 -3 4 -1 2 1 -5 4
// sum = -2 -1 -2 2  3 5 6  1 5  
//newsum=-2  1 -2 4  3 5 6  1 5  <= newsum=max(sum,nums[i])
// ans = -2 -1 -2 4  4 5 6  6 5
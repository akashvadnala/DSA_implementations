#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>& nums,int& target){
    int n=nums.size();
    int dp[n+1][target+1];

    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=target;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++) {
            if(j>=nums[i-1]) dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][target];
}

int main(){
    vector<int> nums{3,4,5,2};
    int target=9;
    cout<<isSubset(nums,target);
    return 0;
}

// Time O(n*target)
// Space O((n+1)*(target+1))

// To know whether there is subset with given sum target

//array=[3,4,5,2]
//target=9


//   0 1 2 3 4 5 6 7 8 9
// 0 1 0 0 0 0 0 0 0 0 0 
// 1 1 0 0 1 0 0 0 0 0 0 
// 2 1 0 0 1 1 0 0 1 0 0 
// 3 1 0 0 1 1 1 0 1 1 1 
// 4 1 0 1 1 1 1 1 1 1 1 
// Length of largest subsequence of which is a substring in b

class Solution {
public:
    int largestSubsequenceAsSubstring(string t1, string t2) {  // t1 in t2
        int n=t1.size(),m=t2.size(),dp[n+1][m+1],ans=0;
        dp[0][0]=0;
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=dp[i][j-1];
            }
            ans=max(ans,dp[i][m]);
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++) cout<<dp[i][j]<<' '; cout<<endl;
        // }
        return ans;
=    }
};
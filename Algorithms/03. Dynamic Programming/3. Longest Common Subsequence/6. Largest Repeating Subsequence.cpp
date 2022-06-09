class Solution {
public:
    int longestRepeatingSubsequence(string& s) {
        int n=s.size();
        int dp[n+1][n+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && s[i]!=s[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
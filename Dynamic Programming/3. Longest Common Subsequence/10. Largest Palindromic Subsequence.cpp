class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n][n];
        if(s[0]==s[n-1]) dp[0][n-1]=1;
        else dp[0][n-1]=0;
        for(int i=1;i<n;i++) dp[i][n-1]=dp[i-1][n-1] || s[i]==s[n-1];
        for(int i=n-2;i>=0;i--) dp[0][i]=dp[0][i+1] || s[0]==s[i];
        for(int i=1;i<n;i++){
            for(int j=n-2;j>=0;j--){
                if(s[i]==s[j]) dp[i][j]=1+dp[i-1][j+1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=n-1;j>=0;j--) cout<<dp[i][j]<<' '; cout<<endl;
        // }
        return dp[n-1][0];
    }
};
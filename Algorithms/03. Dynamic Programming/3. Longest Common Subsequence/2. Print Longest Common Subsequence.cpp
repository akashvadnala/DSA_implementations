class Solution {
public:
    int longestCommonSubsequence(string& t1, string& t2) {
        int n=t1.size(),m=t2.size(),dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) cout<<dp[i][j]<<' '; cout<<endl;
        }
        string ans;
        int i=n,j=m;
        while(i>0 && j>0){
            if(t1[i-1]==t2[j-1]){
                ans=t1[i-1]+ans;
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        cout<<ans<<endl;
        return dp[n][m];
    }
};
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
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
        return dp[n][m];
    }
};

class Solution {
public:
    int longestCommonSubstring(string t1, string t2) {
        int n=t1.size(),m=t2.size();
        int dp[n+1][m+1];
        dp[0][0]=0;
        int mx=0;
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    mx=max(mx,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return mx;
    }
};


//t1 = abcde
//t2 = acef

//   0 a b c d e
// 0 0 0 0 0 0 0
// a 0 1 1 1 1 1
// c 0 1 1 2 2 2
// e 0 1 1 2 2 3
// f 0 1 1 2 2 3

// t1 = abcde
// t2 = acd

//   0 a b c d e
// 0 0 0 0 0 0 0
// a 0 1 0 0 0 0
// c 0 0 0 1 0 0
// d 0 0 0 0 2 0
//

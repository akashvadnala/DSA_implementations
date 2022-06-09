class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.length();
        const int l=2*n+1;
        int a[l];
        for(int i=0;i<l;i++){
            if(i%2==0) a[i]=1;
            else a[i]=0;
        }
        for (int d = 1; d < n; ++d)
            for (int i = 0; i + d < n; ++i) {
            const int j = i + d;
            if(s[i]==s[j]) a[i+j]+=2;
            else a[i+j]=max(a[i+j-1],a[i+j+1]);
        }
        //for(int i=0;i<l;i++) cout<<a[i]<<' '; cout<<endl;
        return a[n-1];
    }
};


// class Solution {
//  public:
//   int longestPalindromeSubseq(string s) {
//     const int n = s.length();
//     vector<vector<int>> dp(n, vector<int>(n));
//     for (int i = 0; i < n; ++i) dp[i][i] = 1;
//     for (int d = 1; d < n; ++d)
//       for (int i = 0; i + d < n; ++i) {
//         const int j = i + d;
//         if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
//         else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//       }
//     // for(auto i:dp){
//     //     for(auto j:i) cout<<j<<' '; cout<<endl;
//     // }
//     return dp[0][n - 1];
//   }
// };
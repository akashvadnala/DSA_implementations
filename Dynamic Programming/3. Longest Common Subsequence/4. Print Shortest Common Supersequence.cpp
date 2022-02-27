class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
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
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++) cout<<dp[i][j]<<' '; cout<<endl;
        // }
        string s,ans;
        int i=n,j=m;
        while(i>0 && j>0){
            if(t1[i-1]==t2[j-1]){
                s=t1[i-1]+s;
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        i=0;
        j=0;
        for(char c:s){
            while(i<n && t1[i]!=c) ans+=t1[i++];
            while(j<m && t2[j]!=c) ans+=t2[j++];
            ans+=c;
            i++;j++;
        }
        while(i<n) ans+=t1[i++];
        while(j<m) ans+=t2[j++];
        return ans;
    }
};
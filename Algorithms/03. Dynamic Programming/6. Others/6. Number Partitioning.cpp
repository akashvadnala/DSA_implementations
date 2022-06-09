#include <bits/stdc++.h>
using namespace std;

int numPartition(int n){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[j]+=dp[i-j];
            
    return dp[n];
}

int main(){
    int n=4;
    cout<<numPartition(n);
    return 0;
}
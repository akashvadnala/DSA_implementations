#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="WWEQERQWQWWRWWERQWEQ";
    unordered_map<char,int> m;
    int n=s.size(),ans=n,k=n/4;
    for(auto& i:s) m[i]++;
    int l=0,r=0;
    while(r<n){
        m[s[r++]]--;
        while(l<r+1 && m['W']<=k && m['E']<=k && m['Q']<=k && m['R']<=k){
            ans=min(ans,r-l);
            ++m[s[l++]];
        }
    }
    cout<<ans<<endl;
    return 0;
}
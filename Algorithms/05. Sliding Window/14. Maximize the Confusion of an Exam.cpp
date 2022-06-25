#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="TTFF";
	int k=2;
	unordered_map<char,int> m;
    int l=0,r=0,ans=0,mx=0;
    while(r<s.size()){
        mx=max(mx,++m[s[r++]]);
        if(mx+k<r-l)
            m[s[l++]]--;
        else ans=max(ans,r-l);
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="aaacb";
	int sum=0,ans=0;
    unordered_map<char,int> m;
    int l=0,r=0;
    while(r<s.size()){
        m[s[r++]]++;
        while(r-l>=3 && m.size()==3){
            if(--m[s[l]]==0)
                m.erase(s[l]);
            l++;
            sum++;
        }
        ans+=sum;
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="abcabcbb";
	int m[26];
	memset(m,-1,sizeof(m));
	int start=-1,ans=0;
	for(int i=0;i<s.size();i++){
		if(m[s[i]-'a']!=-1)
			start=max(start,m[s[i]]-'a');
		ans=max(ans,i-start);
		m[s[i]-'a']=i;
	}
	cout<<ans<<endl;
	return 0;
}
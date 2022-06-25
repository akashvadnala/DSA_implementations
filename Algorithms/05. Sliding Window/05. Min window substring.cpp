#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="ADOBECODEBANC";
	string t="ABC";
	unordered_map<char,int> m;
	for(auto& c:t) m[c]++;
	int count=t.size(),head=0,l=0,r=0,d=INT_MAX;
	while(r<s.size()){
		if(m[s[r++]]-->0) count--;
		while(count==0){
			if(r-l<d) d=r-(head=l);
			if(m[s[l++]]++==0) count++;
		}
	}
	string ans=d==INT_MAX?"":s.substr(head,d);
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="ADOBECODEBANC";
	string t="ABC";
	unordered_map<char,int> m;
	for(auto& c:t) m[c]++;
	int counter=t.size(),end=0,begin=0,head=0,d=INT_MAX;
	while(end<s.size()){
		if(m[s[end++]]-->0) counter--;
		while(counter==0){
			if(end-begin<d) d=end-(head=begin);
			if(m[s[begin++]]++==0) counter++;
		}
	}
	string ans=d==INT_MAX?"":s.substr(head,d);
	cout<<ans<<endl;
	return 0;
}
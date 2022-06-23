#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	if(s.size()<11){
		cout<<endl;
		return 0;
	}
	vector<string> ans;
	unordered_map<string,int> m;
	for(int i=0;i<s.size()-9;i++){
		string str=s.substr(i,10);
		m[str]++;
	}
	for(auto& i:m){
		if(i.second>1) ans.push_back(i.first);
	}
	for(auto& i:ans)
		cout<<i<<' ';
	cout<<endl;
	return 0;
}
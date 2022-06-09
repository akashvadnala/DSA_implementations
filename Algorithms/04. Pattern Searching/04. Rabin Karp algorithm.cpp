#include <bits/stdc++.h>
using namespace std;

int main(){
	string txt="aaaab";
	string pat="aab";
	int n=txt.size();
	int m=pat.size();
	int h=0;
	for(char& i:pat)
		h=h*10+(i-'a')+1;
	int t=0;
	for(int i=0;i<m;i++)
		t=t*10+(txt[i]-'a')+1;
	if(t==h) cout<<0<<endl;
	int p=pow(10,m)/10;
	for(int i=m;i<n;i++){
		t=(t-((txt[i-m]-'a')+1)*p)*10+(txt[i]-'a')+1;
		if(t==h) cout<<i-m+1<<endl;
	}	
	return 0;
}

// time complexity: O(m+n)
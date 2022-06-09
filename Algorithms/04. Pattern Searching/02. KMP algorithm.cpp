#include <bits/stdc++.h>
using namespace std;

int main(){
	string txt="aaaaaaaaaaaad";
	string pat="aad";
	int n=txt.size();
	int m=pat.size();
	vector<int> lps(m,0);
	for(int i=1;i<m;i++){
		if(pat[i]==pat[0]){
			int j=0;
			while(i<m && pat[i]==pat[j]){
				lps[i]=j;
				i++;
				j++;
			}
		}
	}
	for(auto i:lps) cout<<i<<' '; cout<<endl;
	int i=0,j=0;
	while(i<n){
		//cout<<i<<' '<<txt[i]<<' '<<j<<' '<<pat[j]<<endl;
		if(txt[i]==pat[j]){
			i++;
			if(j+1==m){
				cout<<i-m<<endl;
				j=lps[j];
			}
			j++;
		}
		else{
			if(j>0) j=lps[j];
			else i++;
		}
	}
}
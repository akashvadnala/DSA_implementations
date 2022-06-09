#include <bits/stdc++.h>
using namespace std;

int main(){
	string txt="AABAACAADAABAABA";
	string pat="AABA";
	string tmp=txt.substr(0,pat.size());
	if(tmp==pat){ 
		cout<<0<<endl;
	}
	for(int i=pat.size();i<txt.size();i++){
		tmp=tmp.substr(1)+txt[i];
		if(tmp==pat){
			cout<<i-pat.size()+1<<endl;
		}
	}
}
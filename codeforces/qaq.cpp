#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int one=0,two=0,three=0;
	for(auto& i:s){
		if(i=='Q'){
			three+=two;
			one++;
		}
		else if(i=='A'){
			two+=one;
		}
	}
	cout<<three<<endl;
}

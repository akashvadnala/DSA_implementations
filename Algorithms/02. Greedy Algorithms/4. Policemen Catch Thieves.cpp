#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<char> arr{'T', 'T', 'P', 'P', 'T', 'P'};
	int k=2;
	queue<int> p,t;
	int ans=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]=='P'){
			p.push(i);
			if(t.size()>0){
				while(!t.empty() && i-t.front()>k) 
					t.pop();
				if(!t.empty()){
					t.pop();
					p.pop();
					ans++;
				}
			}
		}
		else{
			t.push(i);
			if(p.size()>0){
				while(!p.empty() && i-p.front()>k)
					p.pop();
				if(!p.empty()){
					p.pop();
					t.pop();
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

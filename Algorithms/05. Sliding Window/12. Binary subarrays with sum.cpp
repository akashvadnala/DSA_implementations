#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{1,0,1,0,1};
	int goal=2;
	int sum=0,ans=0;
	unordered_map<int,int> m;
	m[0]=1;
	for(auto& i:nums){
		sum+=i;
		if(m.count(sum-goal))
			ans+=m[sum-goal];
		m[sum]++;
	}
	cout<<ans<<endl;
	return 0;

}
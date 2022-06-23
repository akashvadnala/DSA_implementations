#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{1,2,3,2,2};
	int ans=0;
	unordered_map<int,int> m;
	int l=0,r=0;
	while(r<nums.size()){
		m[nums[r++]]++;
		while(m.size()>2){
			if(--m[nums[l]]==0) m.erase(nums[l]);
			l++;
		}
		ans=max(ans,r-l);
	}
	cout<<ans<<endl;
	return 0;
}
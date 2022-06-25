#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{1,2,1,2,3};
	int k=2;
	vector<int> m(nums.size()+1);
	int l=0,r=0,prefix=0,cnt=0,ans=0;
	while(r<nums.size()){
		if(m[nums[r]]++==0) cnt++;
		if(cnt>k){
			m[nums[l++]]--;
			cnt--;
			prefix=0;
		}
		while(m[nums[l]]>1){
			prefix++;
			m[nums[l++]]--;
		}
		if(cnt==k) ans+=prefix+1;
		r++;
	}
	cout<<ans<<endl;
	return 0;
}
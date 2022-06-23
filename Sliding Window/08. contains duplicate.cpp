// Given an integer array nums and two integers k and t,
// return true if there are two distinct indices i and j
// in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{1,2,3,1};
	int k=3;
	int t=1;
	set<long> s;
	for(int i=0;i<nums.size();i++){
		auto it=s.lower_bound(long(nums[i])-t);
		if(it!=s.end() && abs(nums[i]-*it)<=t){
			cout<<true<<endl;
			return 0;
		}
		s.insert(nums[i]);
		if(i>=k) s.erase(nums[i-k]);
	}
	cout<<false<<endl;
	return 0;
}
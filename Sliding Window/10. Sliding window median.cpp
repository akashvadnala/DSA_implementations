#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> nums{1,3,-1,-3,5,3,6,7};
	int k=3;
	vector<double> ans;
	multiset<double> s(nums.begin(),nums.begin()+k);
	auto it=next(s.begin(),(k-1)/2);
	double median=k&1?*it:(*it+*next(it))/2.0;
	ans.push_back(median);
	for(int i=k;i<nums.size();i++){
		s.insert(nums[i]);
		if(nums[i]<*it) it--;
		if(nums[i-k]<=*it) it++;
		s.erase(s.lower_bound(nums[i - k]));
		median=k&1?*it:(*it+*next(it))/2.0;
		ans.push_back(median);
	}
	for(auto& i:ans) cout<<i<<' ';
	cout<<endl;
	return 0;
}
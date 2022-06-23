#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{2,3,1,2,4,3};
	int target=7;
	int begin=0,end=0,d=INT_MAX,sum=0;
	while(end<nums.size()){
		sum+=nums[end++];
		while(sum>=target){
			if(end-begin<d) d=end-begin;
			sum-=nums[begin++];
		}
	}
	cout<<(d==INT_MAX?0:d)<<endl;
	return 0;
}
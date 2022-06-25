#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{2,3,1,2,4,3};
	int target=7;
	int l=0,r=0,d=INT_MAX,sum=0;
	while(r<nums.size()){
		sum+=nums[r++];
		while(sum>=target){
			if(r-l<d) d=r-l;
			sum-=nums[l++];
		}
	}
	cout<<(d==INT_MAX?0:d)<<endl;
	return 0;
}
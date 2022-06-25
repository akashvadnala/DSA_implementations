#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
	int k=3;
	int zeros=0;
    int l=0,r=0,ans=0;
    while(r<nums.size()){
        if(nums[r++]==0){
            zeros++;
            while(zeros>k){
                if(nums[l++]==0) zeros--;
            }
        }
        ans=max(ans,r-l);
    }
    cout<<ans<<endl;
    return 0;

}
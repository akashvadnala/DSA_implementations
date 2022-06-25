#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{-1,2,1,3,-2,-2,3};
    int k=3;
    int n=arr.size();
	vector<int> v;
    deque<int> dq;
    for(int i=0;i<k;i++)
        if(arr[i]<0) dq.push_back(i);
    
    if(!dq.empty()) v.push_back(arr[dq.front()]);
    else v.push_back(0);
    for(int i=k;i<n;i++){
        if(arr[i]<0) dq.push_back(i);
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        if(!dq.empty()) v.push_back(arr[dq.front()]);
        else v.push_back(0);
    }
    for(auto& i:v) cout<<i<<' '; cout<<endl;
    return 0;
}
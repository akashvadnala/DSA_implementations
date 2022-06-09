#include <bits/stdc++.h>
using namespace std;
vector<int> nearestgreater(vector<int>& arr){
    vector<int> ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int> arr{1,0,2,1,4,5,0,2};
    vector<int> ans=nearestgreater(arr);
    for(auto i:ans) cout<<i<<' ';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &height) {
    int ans = 0;
    height.push_back(0);
    stack<int> st;
    for(int i = 0; i < height.size(); i++){
        while(!st.empty() && height[st.top()]>=height[i]){
            int h=height[st.top()];
            st.pop();
            int j=!st.empty()?st.top():-1;
            if(h*(i-j-1)>ans) ans=h*(i-j-1);
        }
        cout<<endl;
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> height{1,5,3,4,2,6};
    cout<<largestRectangleArea(height);
    return 0;
}
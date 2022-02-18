class Solution {
public:
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
            st.push(i);
        }
        return ans;
    }
};
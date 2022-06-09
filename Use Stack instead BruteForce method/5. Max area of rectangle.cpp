class Solution {
public:
    int getarea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s; 
        vector<int> left_bound(n,0),right_bound(n,n); 
        for(int i=0;i<n;i++) {
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            if(s.empty())  left_bound[i]=0;
            else  left_bound[i] = s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--)  {
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            if(s.empty()) right_bound[i] = n-1;
            else  right_bound[i] = s.top()-1;
            s.push(i);
        }
        int maxi = 0, area;
        for(int i=0; i<n; i++) {
            area = (right_bound[i]-left_bound[i]+1)*heights[i];
            maxi = max(maxi, area);
        }
        return maxi; 
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> arr(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                arr[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]!=0) arr[i][j]+=arr[i-1][j];
            }
        }
        int ans=0;
        for(auto i:arr) ans=max(ans,getarea(i));
        return ans;
    }
};
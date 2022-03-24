class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto i:dislikes){
            i[0]--;
            i[1]--;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<int> color(n,-1);
        for(int k=0;k<n;k++){
            if(color[k]!=-1) continue;
            color[k]=1;
            q.push(k);
            while(!q.empty()){
                int i=q.front();
                q.pop();
                for(auto j:adj[i]){
                    if(color[j]==-1){
                        color[j]=1-color[i];
                        q.push(j);
                    }
                    else if(color[j]==color[i])
                        return false;
                }
            }
        }
        return true;
    }
};
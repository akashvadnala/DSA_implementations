class Solution {
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
    {
        if(visited[curr]==2) return true;
        visited[curr] = 2;
        for(const auto& i:adj[curr])
            if(visited[i]!=1)
                if(isCyclic(adj,visited,i))
                    return true;
        visited[curr] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> adj(numCourses);
        for(const auto& p:prerequisites)
            adj[p[0]].push_back(p[1]);
        
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;++i)
            if(visited[i]==0)
                if(isCyclic(adj,visited,i))
                    return false;
        return true;
    }
};
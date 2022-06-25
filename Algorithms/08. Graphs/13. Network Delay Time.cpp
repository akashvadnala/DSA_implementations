class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> edges(n);
        for(auto i:times){
            edges[i[0]-1].push_back({i[1]-1,i[2]});
        }
        int ans=-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k-1});
        vector<int> visited(n,0);
        int l=0;
        while(!q.empty()){
            auto [delay,i]=q.top();
            q.pop();
            if(visited[i]==1) continue;
            visited[i]=1;
            l++;
            if(l==n) return delay;
            for(const auto& [j,d]:edges[i])
                q.push({delay+d,j});
        }
        return -1;
    }
};
// 743

// Time: O(∣E∣+∣V∣log∣V∣)
// Space: O(∣V∣)
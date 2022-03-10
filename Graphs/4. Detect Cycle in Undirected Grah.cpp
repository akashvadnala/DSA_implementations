#include <bits/stdc++.h>
using namespace std;

bool haveCycle(vector<int> visited,vector<vector<int>>& adj,int i){
    if(visited[i]==2) return true;
    visited[i]++;
    for(int j=0;j<adj[i].size();j++){
        if(haveCycle(visited,adj,adj[i][j]))
            return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(haveCycle(visited,adj,adj[i][j])) 
                return true;
        }
        visited[i]=0;
    }
    return false;
}

int main(){
    vector<vector<int>>adj{
        {1,2,3},
        {0},
        {0,3},
        {0,2}
    };
    cout<<detectCycle(adj);
    return 0;
}
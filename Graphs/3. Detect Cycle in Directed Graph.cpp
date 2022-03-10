#include <bits/stdc++.h>
using namespace std;

bool haveCycle(vector<bool> visited,vector<vector<int>>& adj,int i){
    if(visited[i]) return true;
    visited[i]=true;
    for(int j=0;j<adj[i].size();j++){
        if(haveCycle(visited,adj,adj[i][j]))
            return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>>& adj){
    int n=adj.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            if(haveCycle(visited,adj,adj[i][j])) 
                return true;
        }
        visited[i]=false;
    }
    return false;
}

int main(){
    vector<vector<int>>adj{
        {1},
        {},
        {1,3},
        {4},
        {0,2}
    };
    cout<<detectCycle(adj);
    return 0;
}
//BFS

#include <iostream>
using namespace std;

int main(){
    vector<vector<int>>adj{
        {1,2,3},
        {0},
        {0,3},
        {0,2}
    };
    int n=adj.size();
    vector<int> parent(n,-2);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(parent[i]!=-2) continue;
        parent[i]=-1;
        q.push(i);
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(auto& j:adj[i]){
                if(parent[j]==-2){
                    parent[j]=k;
                    q.push(j);
                }
                else if(parent[i]!=j){
                    cout<<true;
                    return 0;    
                }
            }
        }
        cout<<false;
    }

    return 0;
}



//DFS

#include <bits/stdc++.h>
using namespace std;

bool haveCycle(vector<vector<int>>& adj,int i,vector<int>& visited,int parent){
    visited[i]=true;
    for(auto& j:adj[i]){
        if(!visited[j]){
            if(haveCycle(adj,j,visited,i))
                return true;
        } 
        else if(j!=parent)
            return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>>& adj){
    int n=adj.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i] && haveCycle(adj,i,visited,-1)) 
            return true;
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
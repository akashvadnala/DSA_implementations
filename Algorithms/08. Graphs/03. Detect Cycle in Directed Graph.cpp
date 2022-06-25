#include <bits/stdc++.h>
using namespace std;

bool checkCycle(vector<vector<int>>& adj,int i,vector<int>& vis,vector<int>& dfsvis){
    vis[i]=1;
    dfsvis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j]){
            if(checkCycle(adj,j,vis,dfsvis))
                return true;
        }
        else if(dfsvis[j])
            return true;
    }
    dfsvis[i]=0;
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
    int n=adj.size();
    vector<int> vis(n,0),dfsvis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(checkCycle(adj,i,vis,dfsvis)){
                cout<<"Has cycle"<<endl;
                return 0;
            }
        }
    }
    cout<<"Has no cycle"<<endl;
    return 0;
}
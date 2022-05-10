//BFS

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>adj{
        {1},
        {},
        {1,3},
        {4},
        {0,2}
    };
    
    return 0;
}


//DFS

#include <bits/stdc++.h>
using namespace std;

bool haveCycle(vector<vector<int>>& adj,int i,vector<bool>& visited,vector<bool>& recStack){
    if(!visited[i]){
        visited[i]=true;
        recStack[i]=true;
        for(auto& j:adj)
            if(!visited[i] && haveCycle(adj,j,visited,recStack))
                return true;
            else if(recStack[j])
                return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>>& adj){
    int n=adj.size();
    vector<bool> visited(n,false),recStack(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i] && haveCycle(adj,i,visited,recStack))
            return true;
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
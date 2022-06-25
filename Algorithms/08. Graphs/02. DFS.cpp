#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& graph,int i,int& n,vector<int>& visited){
    if(visited[i]) return;
    cout<<i<<' ';
    visited[i]=1;
    for(int j=0;j<n;j++)
        if(graph[i][j] && !visited[j])
            DFS(graph,j,n,visited);
}

int main(){
    int n=5;
    vector<vector<int>> graph{{0,1,0,1,0},
                             {1,0,1,1,1},
                             {0,1,0,0,1},
                             {1,1,0,0,1},
                             {0,1,1,1,0}};
    vector<int> visited(n,0);
    DFS(graph,0,n,visited);
}

// 0----1----3
//      | \  |
//      |  \ |
//      2----4

// 0 1 2 4 3
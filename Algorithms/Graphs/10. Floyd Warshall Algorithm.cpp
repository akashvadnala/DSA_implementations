#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>& graph){
    vector<vector<int>> dist=graph;
    int n=dist.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(dist[i][k]==INT_MAX) continue;
            for(int j=0;j<n;j++){
                if(dist[k][j]==INT_MAX) continue;
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(auto& i:dist){
        for(auto& j:i)
            cout<<j<<' ';
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> edges{
        {0,1,1},
        {0,2,4},
        {1,2,4},
        {1,3,2},
        {1,4,7},
        {2,3,3},
        {2,4,4},
        {3,5,4},
        {4,3,3},
        {5,4,5}
    };
    int n=6;
    vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
    for(auto& edge:edges)
        graph[edge[0]][edge[1]]=edge[2];
    for(int i=0;i<n;i++)
        graph[i][i]=0;
    floyd_warshall(graph);
    return 0;
}
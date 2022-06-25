#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    vector<vector<int>> graph{{0,1,0,1,0},
                               {1,0,1,1,1},
                               {0,1,0,0,1},
                               {1,1,0,0,1},
                               {0,1,1,1,0}};
    int visited[n]={0};
    queue<int> q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        cout<<i<<' ';
        for(int j=0;j<n;j++){
            if(graph[i][j]==1 && visited[j]==0){
                q.push(j);
                visited[j]=1;
            }
        }
    }
    return 0;
}

// 0----1----3
//      | \  |
//      |  \ |
//      2----4

// 0 1 3 2 4
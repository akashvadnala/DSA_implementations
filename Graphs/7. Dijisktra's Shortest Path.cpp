#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
int main(){
    vector<vector<int>> graph{
        {0,1,4,0,0,0},
        {1,0,4,2,7,0},
        {4,4,0,3,5,0},
        {0,2,3,0,4,6},
        {0,7,5,4,0,7},
        {0,0,0,6,7,0}
    };
    int n=graph.size();
    vector<int> parent(n,-1);
    vector<bool> visited(n,false);
    vector<int> value(n,INT_MAX);
    value[0]=0;
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    pq.push({0,0});
    int i;
    while(!pq.empty()){
        i=pq.top().second;
        pq.pop();
        visited[i]=true;
        for(int j=0;j<n;j++){
            if(graph[i][j] && !visited[j] && value[j]>value[i]+graph[i][j]){
                value[j]=value[i]+graph[i][j];
                pq.push({value[j],j});
            }
        }
    }
    cout<<"parent: "; for(auto i:parent) cout<<i<<' '; cout<<endl;
    cout<<"value: "; for(auto i:value) cout<<i<<' '; cout<<endl;
    return 0;
}

// parent: -1 0 0 1 3 3
// value: 0 1 4 3 7 9 
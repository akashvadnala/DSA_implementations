#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent,int i){
    if(parent[i]==-1)
        return i;
    return parent[i]=find(parent,parent[i]);
}

int main(){
    vector<vector<int>> edgeList{
        {0,1,1},
        {1,3,1},
        {2,4,1},
        {0,2,2},
        {2,3,2},
        {3,4,2},
        {1,2,3},
        {1,4,3},
        {4,5,3},
        {3,5,4}
    };
    int n=6;
    sort(edgeList.begin(),edgeList.end(),[](vector<int>& a,vector<int>& b){return a[2]<b[2];});
    vector<int> parent(n,-1);
    vector<int> rank(n,0);
    vector<vector<int>> spanEdges;
    int from,to;
    for(auto edge:edgeList){
        from=find(parent,edge[0]);
        to=find(parent,edge[1]);
        if(from==to) continue;
        if(rank[to]>rank[from]){
            parent[from]=to;
            rank[to]+=rank[from];
        }
        else if(rank[from]>rank[to]){
            parent[to]=from;
            rank[from]+=rank[to];
        }
        else{
            parent[from]=to;
            rank[to]++;
        }
        spanEdges.push_back(edge);
    }
    for(auto edge:spanEdges) cout<<edge[0]<<' '<<edge[1]<<' '<<edge[2]<<endl;
    return 0;
}

// 0 1 1
// 1 3 1
// 2 4 1
// 0 2 2
// 4 5 3
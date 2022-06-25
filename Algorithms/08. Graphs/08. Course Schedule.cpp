#include <bits/stdc++.h>
using namespace std;

bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
{
    if(visited[curr]==2) return true;
    visited[curr] = 2;
    for(const auto& i:adj[curr])
        if(visited[i]!=1)
            if(isCyclic(adj,visited,i))
                return true;
    visited[curr] = 1;
    return false;
}

int main(){
    int numCourses=6;
    vector<vector<int>> prerequisites  {{1,2},
                                        {2,3},
                                        {1,4},
                                        {2,5},
                                        {4,5}
                                        };
    vector<vector<int>> adj(numCourses);
    for(const auto& p:prerequisites)
        adj[p[0]].push_back(p[1]);  
    vector<int> visited(numCourses,0);
    for(int i=0;i<numCourses;++i)
        if(visited[i]==0)
            if(isCyclic(adj,visited,i)){
                cout<<"Cannot schedule the course"<<endl;
                return 0;
            }
    cout<<"Can schedule the course"<<endl;
    return 0;
}


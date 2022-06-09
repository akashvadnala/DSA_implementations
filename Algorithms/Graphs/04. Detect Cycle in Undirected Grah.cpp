// //BFS

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<vector<int>>adj{
//         {1,2,3},
//         {0},
//         {0,3},
//         {0,2}
//     };
//     int n=adj.size();
//     vector<int> parent(n,-2);
//     queue<int> q;
//     for(int i=0;i<n;i++){
//         if(parent[i]!=-2) continue;
//         parent[i]=-1;
//         q.push(i);
//         while(!q.empty()){
//             int k=q.front();
//             q.pop();
//             for(auto& j:adj[i]){
//                 if(parent[j]==-2){
//                     parent[j]=k;
//                     q.push(j);
//                 }
//                 else if(parent[i]!=j){
//                     cout<<true;
//                     return 0;    
//                 }
//             }
//         }   
//     }
//     cout<<false;
//     return 0;
// }



//DFS

#include <bits/stdc++.h>
using namespace std;

bool checkCycle(vector<vector<int>>& adj,int i,vector<int>& vis,int parent){
    vis[i]=true;
    for(auto& j:adj[i]){
        if(!vis[j]){
            if(checkCycle(adj,j,vis,i))
                return true;
        } 
        else if(j!=parent)
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
    int n=adj.size();
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
        if(!vis[i])
            if(checkCycle(adj,i,vis,-1)) 
                return true;
    }
    cout<<"Has no cycle"<<endl;
    return 0;
}
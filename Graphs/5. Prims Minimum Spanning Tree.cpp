#include <bits/stdc++.h>
using namespace std;


int minwt(vector<int>& wt,vector<bool>& setwt){
    int mn=INT_MAX,k;
    for(int i=0;i<wt.size();i++){
        if(!setwt[i] && wt[i]<mn){
            mn=wt[i];
            k=i;
        }
    }
    return k;
}

void primMST(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int> wt(n,INT_MAX);
    vector<bool> setwt(n,false);
    vector<int> parent(n);
    wt[0]=0;
    parent[0]=-1;
    int i;
    for(int count=1;count<n;count++){  //from count=1 coz wt[0] already has given   
        i=minwt(wt,setwt);
        setwt[i]=true;
        for(int j=0;j<n;j++){
            if(graph[i][j] && !setwt[j] && wt[j]>graph[i][j]){
                wt[j]=graph[i][j];
                parent[j]=i;
            }
        }
    }
    cout<<"wt: "; for(auto& i:wt) cout<<i<<' '; cout<<endl;
    cout<<"parent: "; for(auto& i:parent) cout<<i<<' '; cout<<endl;
}

int main(){
    vector<vector<int>> graph {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    primMST(graph);
    return 0;
}

//         0 1 2 3 4
// wt:     0 2 3 6 5
//parent: -1 0 1 0 1

//    2    5
//  0----1----4
//  | 8/ | 7/ |
// 6| / 3| /  |9
//  3    2    |
//  |         |
//  ----------   

// primMST

//    2    5
//  0----1----4
//  |    |  
// 6|   3|   
//  3    2    
//  




#include <bits/stdc++.h>
using namespace std;

int countsq(vector<vector<int>> matrix){
    int n=matrix.size(),m=matrix[0].size();
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(matrix[i][j]==1)
                matrix[i][j]=min(matrix[i][j],min(matrix[i][j-1],matrix[i-1][j]))+1;
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            sum+=matrix[i][j];
    return sum;
}

int main(){
    vector<vector<int>> matrix {{1,0,1},
                                {1,1,0},
                                {1,1,0}};
    cout<<countsq(matrix);
    return 0;
} 
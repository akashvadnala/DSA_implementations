#include <bits/stdc++.h>
using namespace std;

pair<int,int> find(vector<int>& con,vector<int>& dia,int i){
	if(con[i]==-1) return {i,INT_MAX};
	pair<int,int> p=find(con,dia,con[i]);
	int x=dia[i];
	con[i]=-1;
	dia[i]=INT_MAX;
	return {p.first,min(x,p.second)};
}

vector<vector<int>> waterConnection(vector<int>& con,vector<int>& dia){
	vector<vector<int>> ans;
	for(int i=0;i<con.size();i++){
		if(con[i]==-1) continue;
		pair<int,int> p=find(con,dia,i);
		con[i]=p.first,
		dia[i]=p.second;
	}
	for(int i=0;i<con.size();i++)
		if(con[i]!=-1) ans.push_back({i+1,con[i]+1,dia[i]});
	return ans;
}

int main(){
	int n=9;
	vector<vector<int>> arr{{7,4,98},
							{5,9,72},
							{4,6,10},
							{2,8,22},
							{9,7,17},
							{3,1,66}};
	vector<int> con(n,-1);
	vector<int> dia(n,INT_MAX);
	for(auto& i:arr){
		con[i[0]-1]=i[1]-1;
		dia[i[0]-1]=i[2];
	}
	vector<vector<int>> ans=waterConnection(con,dia);
	cout<<ans.size()<<endl;
	for(auto& i:ans)
		cout<<i[0]<<' '<<i[1]<<' '<<i[2]<<endl;
	return 0;
}
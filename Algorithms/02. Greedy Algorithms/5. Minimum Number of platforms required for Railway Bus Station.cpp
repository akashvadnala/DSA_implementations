#include <bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>
int main(){
	vector<int> arr{900,940,950,1100,1500,1800};
	vector<int> dep{910,1200,1120,1130,1900,2000};
	vector<ipair> time;
	for(int i=0;i<arr.size();i++)
		time.push_back({dep[i],arr[i]});
	sort(time.begin(),time.end(),[](ipair& a,ipair& b){return a.second<b.second;});
	priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
	int ans=0;
	for(auto& i:time){
		if(!pq.empty() && pq.top().first<i.second){
			pq.pop();
			pq.push(i);
		}
		else{
			pq.push(i);
			ans++;
		}
	}
	cout<<ans<<endl;
}
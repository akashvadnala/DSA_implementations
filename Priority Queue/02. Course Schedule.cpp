#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>> courses{{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
	sort(courses.begin(),courses.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});
    int time=0,ans=0;
    priority_queue<int> pq;
    for(auto& i:courses){
        pq.push(i[0]);
        time+=i[0];
        if(time>i[1]){
            time-=pq.top();
            pq.pop();
        }
    }
    cout<<pq.size()<<endl;
    return 0;
}
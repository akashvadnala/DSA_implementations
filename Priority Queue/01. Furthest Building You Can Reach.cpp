#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> heights{4,12,2,7,3,18,20,3,19};
	int bricks=10;
	int ladders=2;
	int n=heights.size(),bricksum=0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<n;i++){
        int diff=heights[i]-heights[i-1];
        if(diff<=0) continue;
        q.push(diff);
        if(q.size()>ladders){
            bricksum+=q.top();
            q.pop();
        }
        if(bricksum>bricks){ 
        	cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<n-1<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> v;
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    v.push_back(arr[dq.front()]);
    for(int i=k;i<arr.size();i++){
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        v.push_back(arr[dq.front()]);
    }
    for(auto& i:v) cout<<i<<' ';
    cout<<endl;
    return 0;
}


// Time: O(n)
// Space: O(n)

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
vector<int> firstNegative(vector<int> arr, int n, int k) {
	vector<int> v;
    deque<int> dq;
    for(int i=0;i<k;i++)
        if(arr[i]<0) dq.push_back(i);
    
    if(!dq.empty()) v.push_back(arr[dq.front()]);
    else v.push_back(0);
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        if(arr[i]<0) dq.push_back(i);
        if(!dq.empty()) v.push_back(arr[dq.front()]);
        else v.push_back(0);
    }
    return v;
}
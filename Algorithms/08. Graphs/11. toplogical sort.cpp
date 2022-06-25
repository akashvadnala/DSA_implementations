class Solution{
    void tsort(vector<int> adj[],int i,vector<bool>& visited,stack<int>& st){
        visited[i]=true;
        for(auto& j:adj[i])
            if(!visited[j])
                tsort(adj,j,visited,st);
        st.push(i);
    }
	public: 
	vector<int> topoSort(int V, vector<int> adj[]){
	    vector<bool> visited(V,false);
	    stack<int> st;
	    vector<int> ans;
	    for(int i=0;i<V;i++)
	        if(!visited[i])
	            tsort(adj,i,visited,st);
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

// 0 []
// 1 []
// 2 [3]
// 3 [1]
// 4 [0,1]
// 5 [0,2]
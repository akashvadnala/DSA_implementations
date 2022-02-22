class Solution{
	public:
	int subsetCount(int arr[], int n, int sum)
	{
       vector<vector<int>> t(n+1,vector<int>(sum+1,0));
       for(int i=0;i<n+1;i++) t[i][0] = 1;
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j)
                    t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]]);
                else
                    t[i][j] = t[i-1][j];
            }
            
        return t[n][sum];
	} 
};


// To count the number of subsets having the target sum
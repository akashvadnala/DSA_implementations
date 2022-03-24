class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	vector<long long> temp(n);
    	for(int i=0;i<n;i++){
    	    temp[i]=arr[i];
    	}
    	int l=0,r=n-1,k=0;
    	while(l<r){
    	    arr[k++]=temp[r--];
    	    arr[k++]=temp[l++];
    	}
    	if(l==r) arr[k]=temp[l];
    }
};
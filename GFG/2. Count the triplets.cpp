class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    unordered_map<int,int> m;
	    int c=0;
	    for(int i=0;i<n;i++) m[arr[i]]++;
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(m.find(arr[i]+arr[j])!=m.end()) c++;
	        }
	    }
	    return c;
	}
};

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(1)

// Example 1:

// Input:
// N = 4
// arr[] = {1, 5, 3, 2}
// Output: 2
// Explanation: There are 2 triplets: 
// 1 + 2 = 3 and 3 +2 = 5 
// â€‹Example 2:

// Input: 
// N = 3
// arr[] = {2, 3, 4}
// Output: 0
// Explanation: No such triplet exits
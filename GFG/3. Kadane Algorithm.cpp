class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int mx=INT_MIN,ans=0,sum=0;
        for(int i=0;i<n;i++){
            if(mx<arr[i]) mx=arr[i];
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
            sum=max(0,sum);
            if(ans<sum) ans=sum;
        }
        if(mx<0) return mx;
        return ans;
    }
};


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Example 1:

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.
// Example 2:

// Input:
// N = 4
// Arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)
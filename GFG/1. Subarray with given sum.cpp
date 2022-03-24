class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int A[], int n, long long s)
    {
        long long sum=0;
        int l=0;
        for(int r=0;r<n;r++){
            sum+=A[r];
            if(sum==s) return {l+1,r+1};
            else if(sum>s){
                while(l<=r && sum>s){
                    sum-=A[l++];
                }
                if(sum==s) return {l+1,r+1};
            }
        }
        return {-1};
    }
};

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Example 1:

// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4
// Explanation: The sum of elements 
// from 2nd position to 4th position 
// is 12.
 

// Example 2:

// Input:
// N = 10, S = 15
// A[] = {1,2,3,4,5,6,7,8,9,10}
// Output: 1 5
// Explanation: The sum of elements 
// from 1st position to 5th position
// is 15.
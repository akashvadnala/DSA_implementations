class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int sum=accumulate(array.begin(),array.end(),0);
        int nsum=(n*(n+1))/2;
        return nsum-sum;
    }
};


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Example 1:

// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4
// Example 2:

// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9

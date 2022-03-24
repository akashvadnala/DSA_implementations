class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=0,j=0,l=n-1;
            while(i<n && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[l],arr2[j]);
                    l--;
                    j++;
                }
                else i++;
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};


// Expected Time Complexity:  O((n+m) log(n+m))
// Expected Auxilliary Space: O(1)


// Example 1:

// Input: 
// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 0 1 2 3 5 6 7 8 9.
// Example 2:

// Input: 
// n = 2, arr1[] = [10, 12] 
// m = 3, arr2[] = [5 18 20]
// Output: 
// arr1[] = [5 10]
// arr2[] = [12 18 20]
// Explanation:
// After merging two sorted arrays 
// we get 5 10 12 18 20.


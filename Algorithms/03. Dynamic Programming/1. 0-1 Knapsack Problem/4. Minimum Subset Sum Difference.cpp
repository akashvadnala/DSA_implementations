class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int n=stones.size();
        vector<vector<int>> t(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++) t[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=2*stones[i-1]) t[i][j]=t[i-1][j] || t[i-1][j-2*stones[i-1]]; 
                else t[i][j]=t[i-1][j];  //Not sending the element from array1 to array to.
            }
        }
        n=t.size()-1;
        for(int i=sum;i>0;i--) if(t[n][i]==1) return sum-i;
        return sum;
    }
};

//Patition of array into two such that difference of sum of elements of arrays is minimum

//array=[2,7,4,1,8,1] -> sum=23 

//array1=[2,8,1] ->sum=11

//array2=[7,4,1] -> sum=12

//difference = 1

// First of all, we take two empty arrays, then all elements are pushed to array1 and array2 keep empty now the difference is sum of elements.
// Now we send one element from array1 to array2 so that difference=sum-2*element
// Repeatedly we try for all elements for in the above way or sending the 2nd element while keeping first sent eleent as it is.

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
// 1 0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0 
// 1 0 0 0 1 0 0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0  0  0 
// 1 0 0 0 1 0 0 0 0 0 0  0  0  0  1  0  0  0  1  0  0  0  0  0 
// 1 0 0 0 1 0 0 0 1 0 0  0  1  0  1  0  0  0  1  0  0  0  1  0 
// 1 0 1 0 1 0 1 0 1 0 1  0  1  0  1  0  1  0  1  0  1  0  1  0 
// 1 0 1 0 1 0 1 0 1 0 1  0  1  0  1  0  1  0  1  0  1  0  1  0 
// 1 0 1 0 1 0 1 0 1 0 1  0  1  0  1  0  1  0  1  0  1  0  1  0 

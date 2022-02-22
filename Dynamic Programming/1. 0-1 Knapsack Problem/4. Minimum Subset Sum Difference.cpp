class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>> t(stones.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<t.size();i++) t[i][0]=1;
        for(int i=1;i<t.size();i++){
            for(int j=0;j<t[0].size();j++){
                if(j>=2*stones[i-1]) t[i][j]=t[i-1][j] || t[i-1][j-2*stones[i-1]];
                else t[i][j]=t[i-1][j];
            }
        }
        int n=t.size()-1;
        for(int i=sum;i>=0;i--) if(t[n][i]==1) return sum-i;
        return sum;
    }
};

//Patition of array into two such that difference of sum of elements of arrays is minimum

//array=[2,7,4,1,8,1] -> sum=23

//array1=[2,8,1] ->sum=11

//array2=[7,4,1] -> sum=12

//difference = 1
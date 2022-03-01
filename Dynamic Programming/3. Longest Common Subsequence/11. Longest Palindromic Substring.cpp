class Solution {
public:
    int start=0;
   int len = 0;
    void solve(string &s,int i,int j){
        while(i>=0 && j<=s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        i++;
        j--;
        if(j-i+1>len){
            len=j-i+1;
            start=i;
        } 
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            solve(s,i,i);
            solve(s,i,i+1);
        }
        return s.substr(start,len);
    }
};
class Solution {
    int solve(const string& s,int l,int r) {
        int count = 0;
        while (l>=0 && r<s.length() && s[l]==s[r]) {
            ++count;
            --l;
            ++r;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i=0;i<s.length();++i) {
            ans += solve(s,i,i);
            ans += solve(s,i,i+1);
        }
        return ans;
    }
};
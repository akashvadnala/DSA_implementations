class Solution {
public:
    unordered_map<string,bool> mem;
    bool getc(string& s1,string& s2,string& s3,int i,int j,int k){
        int n3=s3.size(),n1=s1.size(),n2=s2.size();
        if(k==n3 && i==n1 && j==n2) return true;
        string key=to_string(i)+'*'+to_string(j)+'*'+to_string(k);
        if(mem.find(key)!=mem.end()) return mem[key];
        if(i==s1.size()){
            mem[key]=(s2[j]==s3[k])?getc(s1,s2,s3,i,j+1,k+1):false;
            return mem[key];
        }
        if(j==s2.size()){
            mem[key]=(s1[i]==s3[k])?getc(s1,s2,s3,i+1,j,k+1):false;
            return mem[key];
        }
        bool one=false,two=false;
        if(s1[i]==s3[k]) one=getc(s1,s2,s3,i+1,j,k+1);
        if(s2[j]==s3[k]) two=getc(s1,s2,s3,i,j+1,k+1);
        mem[key]=one || two;
        return mem[key];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        return getc(s1,s2,s3,0,0,0);
    }
};


// Using recursion and memorisation


class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    const int m = s1.length();
    const int n = s2.length();
    if (m + n != s3.length())
      return false;

    bool dp[n + 1];
    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= n; ++j)
        if (i == 0 && j == 0)
          dp[j] = true;
        else if (i == 0)
          dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        else if (j == 0)
          dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
        else
          dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1] ||
                  dp[j - 1] && s2[j - 1] == s3[i + j - 1];

    return dp[n];
  }
};

// dynamic programming
class Solution {
public:
    int minDeletions(string s) {
        const int n = s.length();
        const int l=2*n+1;
        int a[l];
        for(int i=0;i<l;i++){
            if(i%2==0) a[i]=1;
            else a[i]=0;
        }
        for (int d = 1; d < n; ++d)
            for (int i = 0; i + d < n; ++i) {
            const int j = i + d;
            if(s[i]==s[j]) a[i+j]+=2;
            else a[i+j]=max(a[i+j-1],a[i+j+1]);
        }
        //for(int i=0;i<l;i++) cout<<a[i]<<' '; cout<<endl;
        return n-a[n-1];
    }
};
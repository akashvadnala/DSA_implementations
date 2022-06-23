#include <bits/stdc++h>
using namespace std;
int main(){
    string s="cbaebabacd";
    string p="abc";
    int n=p.size(),m=s.size();
    vector<int> arr,smap(26,0),pmap(26,0);
    if(s.size()<p.size()) return arr;
    for(int i=0;i<n;i++){
        smap[s[i]-'a']++;
        pmap[p[i]-'a']++;
    }
    if(smap==pmap) arr.push_back(0);
    for(int i=n;i<m;i++){
        smap[s[i]-'a']++;
        smap[s[i-n]-'a']--;
        if(smap==pmap) arr.push_back(i-n+1);
    }
    return arr;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s="abbca";
	int m[26]={0};
    long long sum=0,ans=0;
    for(int i=0;i<s.size();i++){
        sum=sum+i; //prev sum added by i;
        sum++; //this character added to ans string
        sum-=m[s[i]-'a']; // previous repeated character i is removed
        m[s[i]-'a']=i+1;
        ans+=sum;
    }
    cout<<ans<<endl;
    return 0;
}
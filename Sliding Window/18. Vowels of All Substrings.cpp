#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') 
    	return true;
    return false;
}

int main(){
	string s="ababa";
	long long sum=0,ans=0;
    int l=0,r=0;
    while(r<s.size()){
        if(isvowel(s[r])){
            sum+=r+1; //sum =sum+(r-l)+l+1;
            ans+=sum;
            l=r;
        }
        else ans+=sum;
        r++;
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	string str="acccbaaacccbaac";
	int n=str.size();
	vector<int> arr(n,0);
	int i=1,j=0;
	while(i<n){
		if(str[i]==str[j]){
			arr[i++]=++j;
		}
		else{
			if(j>0) j=arr[j-1];
			else i++;
		}
	}
	cout<<arr.back()<<endl;
}
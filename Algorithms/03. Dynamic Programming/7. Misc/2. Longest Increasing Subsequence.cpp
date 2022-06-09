#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr{10,22,9,33,21,50,41,60,80};
	int n=arr.size();
	vector<int> temp;
	temp.push_back(arr[0]);
	int len=1;
	for(int i=1;i<n;i++){
		if(temp.back()<arr[i]){
			temp.push_back(arr[i]);
			len++;
		}
		else{
			int ind=*upper_bound(temp.begin(),temp.end(),arr[i]);
			temp[ind]=arr[i];
		}
	}
	cout<<len<<endl;
}


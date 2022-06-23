#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>> fruits{{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
	int startPos=4;
	int k=4;

    int start=max(startPos-k,min(startPos,fruits[0][0]));
    int end=min(startPos+k,max(startPos,fruits.back()[0]));
    int n=end-start+1;
    vector<int> arr(n);
    int mid=startPos-start;
    // cout<<mid<<endl;
    for(auto& fruit:fruits)
        if(fruit[0]-start>=0 && fruit[0]-start<n) arr[fruit[0]-start]=fruit[1];
    for(int i=mid+1;i<n;i++)
        arr[i]+=arr[i-1];
    for(int i=mid-1;i>=0;i--)
        arr[i]+=arr[i+1];
    // for(auto& i:arr) cout<<i<<' '; cout<<endl;
    int ans=arr[mid];
    for(int i=mid+1;i<n;i++){
        ans=max(ans,arr[i]+((2*i-k-mid<=mid)?arr[max(0,2*i-k-mid)]-arr[mid]:0)); //mid-(k-2*(i-mid))
        // cout<<ans<<' '<<arr[i]<<' '<<((2*i-k-mid<=mid)?arr[max(0,2*i-k-mid)]-arr[mid]:0)<<endl;
    }
    // cout<<endl;
    for(int i=mid-1;i>=0;i--){
        ans=max(ans,arr[i]+((2*i+k-mid>=mid)?arr[min(n-1,2*i+k-mid)]-arr[mid]:0)); //mid+(k-2*(mid-i))
        // cout<<ans<<' '<<arr[i]<<' '<<((2*i+k-mid>=mid)?arr[min(n-1,2*i+k-mid)]-arr[mid]:0)<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
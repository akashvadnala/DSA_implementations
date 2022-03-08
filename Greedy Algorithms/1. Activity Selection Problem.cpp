class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> time;
        for(int i=0;i<start.size();i++){
            time.push_back({start[i],end[i]});
        }
        for(auto i:time) cout<<i.first<<' '<<i.second<<endl;
        sort(time.begin(),time.end());
        int i=0,ans=1;
        for(int j=1;j<start.size();j++){
            if(time[i].second<time[j].first){
                cout<<i<<' '<<j<<endl;
                ans++;
                i=j;
            }
        }
        return ans;
    }
};

// time= {{1,10},{2,3},{4,5}}
// After sorting:
// time = {{2,3},{4,5},{1,10}}
//
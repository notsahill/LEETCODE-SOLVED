class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        int n=access_times.size();
        sort(access_times.begin(),access_times.end());
        map<string,int> mp;
        for(int i=0;i<n-2;i++)
        {
            if(mp.find(access_times[i][0])==mp.end() and access_times[i][0]==access_times[i+2][0])
            {
                int t2=stoi(access_times[i+2][1]);
                int t1=stoi(access_times[i][1]);
                if(t2-t1<100)
                {
                    ans.push_back(access_times[i][0]);
                    mp[access_times[i][0]]++;
                }
            }
        }
        return ans;
    }
};
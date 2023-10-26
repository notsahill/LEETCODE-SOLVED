class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int MOD=1e9+7;
        unordered_map<int,long long> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int possibleLC= arr[j];
                int possibleRC= arr[i]/arr[j];

                if(arr[i]%arr[j]==0 and mp.find(possibleRC)!=mp.end())
                {
                    mp[arr[i]]+= mp[possibleLC]* mp[possibleRC];
                }
            }
        }
        long long int c=0;
        for(auto a:mp)
        {
            c= (c+a.second)%MOD;
        }
        return c%MOD;
    }
};
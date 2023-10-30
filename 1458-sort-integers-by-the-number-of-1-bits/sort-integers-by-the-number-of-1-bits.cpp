class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++)
        {
            int c=__builtin_popcount(arr[i]);
            v.push_back({c,arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto a:v)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};
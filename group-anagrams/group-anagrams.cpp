class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> um;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            um[strs[i]].push_back(s);
        }
        for(auto a:um)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};
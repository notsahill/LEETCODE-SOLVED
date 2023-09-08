class Solution {
public:
    int h(int idx,string &s,set<string> &dict,vector<int> &dp)
    {
        if(idx>=s.size()) return 1;
        string temp="";
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++)
        {
            temp+=s[i];
            if(dict.find(temp)!=dict.end())
            {
                if(h(i+1,s,dict,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,-1);
        return h(0,s,dict,dp);
    }
};
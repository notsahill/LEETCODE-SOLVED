class Solution {
public:
    int dp[301];
    int helper(int i,string s,set<string> wD)
    {
        if(i>=s.size()) return 1;
        string temp;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(wD.find(temp)!=wD.end())
            {
                if(helper(j+1,s,wD)) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& woD) 
    {
        set<string> str;
        for(auto a:woD) str.insert(a);
        memset(dp,-1,sizeof(dp));
        return helper(0,s,str);    
    }
};
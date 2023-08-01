class Solution {
public:
    int h(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if(j==t.size()) return 1;
        if(i==s.size() and j!=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=h(i+1,j+1,s,t,dp)+h(i+1,j,s,t,dp);
        }
        else return dp[i][j]=h(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int> (t.size(),-1));
        return h(0,0,s,t,dp);
    }
};
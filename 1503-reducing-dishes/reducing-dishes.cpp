class Solution {
public:
    int h(int idx,int t,vector<int> &s,vector<vector<int>> &dp)
    {
        if(idx>=s.size()) return 0;
        if(dp[idx][t]!=-1) return dp[idx][t];
        int inc=h(idx+1,t+1,s,dp) + s[idx]*t;
        int exc=h(idx+1,t,s,dp);
        return dp[idx][t]=max(inc,exc);
    }
    int maxSatisfaction(vector<int> &s) 
    {
        vector<vector<int>> dp(s.size(),vector<int> (501,-1));
        sort(s.begin(),s.end());
        return h(0,1,s,dp);
    }
};
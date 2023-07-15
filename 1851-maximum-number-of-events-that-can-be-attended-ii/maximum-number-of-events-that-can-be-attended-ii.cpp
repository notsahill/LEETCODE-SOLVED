class Solution {
public:
    int helper(int idx,vector<vector<int>> &events,int k,int end,vector<vector<int>> &dp)
    {
        if(k==0) return 0;
        if(idx>=events.size()) return 0;
        if(events[idx][0]<=end) return helper(idx+1,events,k,end,dp);
        if(dp[idx][k]!=-1) return dp[idx][k];
        int inc=0,exc=0;
        inc=helper(idx+1,events,k-1,events[idx][1],dp)+events[idx][2];
        exc=helper(idx+1,events,k,end,dp);
        return dp[idx][k]=max(inc,exc);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return helper(0,events,k,0,dp);
    }
};
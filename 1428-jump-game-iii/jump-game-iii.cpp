class Solution {
public:
    bool helper(vector<int> &arr,int idx,vector<int> &vis,vector<int> &dp)
    {
        if(idx<0 || idx>=arr.size() || vis[idx]) return false;
        if(arr[idx]==0) return true;
        vis[idx]=1;
        if(dp[idx]!=-1) return dp[idx];
        bool x=helper(arr,idx+arr[idx],vis,dp);
        bool y=helper(arr,idx-arr[idx],vis,dp);
        return dp[idx]=x||y;
    }
    bool canReach(vector<int>& arr, int start) 
    {
        vector<int> vis(arr.size(),0);
        vector<int> dp(arr.size(),-1);
        return helper(arr,start,vis,dp);
    }
};
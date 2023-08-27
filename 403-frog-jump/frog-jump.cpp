class Solution {
public:
    bool h(int idx,int k,vector<int> &stones,unordered_map<int,int> &mp,vector<vector<int>> &dp)
    {
        if(idx==stones.size()-1) return true;
        if(idx>=stones.size()) return false;
        bool ans=false;
        if(dp[idx][k]!=-1) return dp[idx][k];
        if(mp[stones[idx]+k]>0) ans|=h(mp[stones[idx]+k],k,stones,mp,dp);
        if(k>1 and mp[stones[idx]+k-1]>0) ans|=h(mp[stones[idx]+k-1],k-1,stones,mp,dp);
        if(mp[stones[idx]+k+1]>0) ans|=h(mp[stones[idx]+k+1],k+1,stones,mp,dp);
        return dp[idx][k]=ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp;
        if(stones[1]-stones[0]!=1) return false;
        vector<vector<int>> dp(stones.size()+1,vector<int> (stones.size()+1,-1));
        for(int i=0;i<stones.size();i++)
        {
            mp[stones[i]]=i;
        }
        return h(1,1,stones,mp,dp);
    }
};
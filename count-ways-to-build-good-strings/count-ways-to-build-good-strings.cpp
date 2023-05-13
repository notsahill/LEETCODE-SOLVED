class Solution {
public:
    int mo=1e9+7;
    int helper(int i,int l,int h,int z,int o,vector<int> &dp)
    {
        if(i>h) return 0;
        if(dp[i]!=-1) return dp[i];
        int a=helper(i+z,l,h,z,o,dp)%mo;
        int b=helper(i+o,l,h,z,o,dp)%mo;
        if(i>=l and i<=h) return dp[i]=(a+b+1)%mo;
        return dp[i]=(a+b)%mo;
    }
    int countGoodStrings(int l, int h, int z, int o) 
    {
        vector<int> dp(h+1,-1);
        return helper(0,l,h,z,o,dp);
    }
};
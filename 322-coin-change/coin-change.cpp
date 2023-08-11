class Solution {
public:
    int f(int idx,vector<int>& coins, int amount,vector<vector<int>> &dp)
    {
        if(idx<=0)
        {
            if(amount%coins[idx]==0) return amount/coins[idx];
            return INT_MAX-1;
        }
        if(amount==0) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int y=INT_MAX-1;
        int x=f(idx-1,coins,amount,dp);
        if(coins[idx]<=amount) y=1+f(idx,coins,amount-coins[idx],dp);
        return dp[idx][amount]=min(x,y);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int x=f(n-1,coins,amount,dp);
        return x==INT_MAX-1? -1:x;
    }
};
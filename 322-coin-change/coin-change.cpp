class Solution {
public:
    int h(int idx,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(idx<0) return INT_MAX-1;
        if(idx==0)
        {
            if(amount%coins[idx]==0) return amount/coins[idx];
            return INT_MAX-1;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int inc=INT_MAX-1;
        if(coins[idx]<=amount) inc=1+h(idx,amount-coins[idx],coins,dp);
        int exc=h(idx-1,amount,coins,dp);
        return dp[idx][amount]=min(inc,exc);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int x= h(n-1,amount,coins,dp);
        return x==INT_MAX-1? -1: x;
    }
};
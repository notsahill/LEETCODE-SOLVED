class Solution {
public:
    int h(int idx,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(idx<0) return 0;
        if(idx==0)
        {
            if(amount%coins[idx]==0) return amount/coins[idx];
            return INT_MAX-1;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int a=INT_MAX-1;
        if(coins[idx]<=amount) a=1+h(idx,amount-coins[idx],coins,dp);
        int b=h(idx-1,amount,coins,dp);
        return dp[idx][amount]=min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int ans=h(n-1,amount,coins,dp);
       
        return ans==INT_MAX-1?-1:ans;
    }
};
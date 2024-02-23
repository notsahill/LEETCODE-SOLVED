class Solution {
public:
    int h(int idx,int canBuy,vector<int> &prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(idx>=n) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        int ans=h(idx+1,canBuy,prices,dp);
        if(canBuy){
            ans=max(-prices[idx]+h(idx+1,!canBuy,prices,dp),ans);
        }else{
            ans=max(prices[idx]+h(idx+1,!canBuy,prices,dp),ans);
        }
        return dp[idx][canBuy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return h(0,1,prices,dp);
    }
};
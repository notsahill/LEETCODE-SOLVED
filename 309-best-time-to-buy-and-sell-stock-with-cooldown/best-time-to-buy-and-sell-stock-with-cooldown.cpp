class Solution {
public:
    int h(int idx,int canBuy,vector<int> &prices,vector<vector<int>> &dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        if(canBuy){
            return dp[idx][canBuy]=max(-prices[idx]+h(idx+1,!canBuy,prices,dp),h(idx+1,canBuy,prices,dp));
        }
        else{
            return dp[idx][canBuy]=max(prices[idx]+h(idx+2,!canBuy,prices,dp),h(idx+1,canBuy,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        return h(0,1,prices,dp);
    }
};
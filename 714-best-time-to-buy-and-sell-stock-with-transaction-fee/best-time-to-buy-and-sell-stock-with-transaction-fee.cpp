class Solution {
public:
    int h(int idx,int canBuy,int &fee,vector<int> &prices,vector<vector<int>> &dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        if(canBuy){
            return dp[idx][canBuy]=max(-prices[idx]+h(idx+1,!canBuy,fee,prices,dp),h(idx+1,canBuy,fee,prices,dp));
        }else{
            return dp[idx][canBuy]=max(prices[idx]-fee+h(idx+1,!canBuy,fee,prices,dp),h(idx+1,canBuy,fee,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return h(0,1,fee,prices,dp);
    }
};
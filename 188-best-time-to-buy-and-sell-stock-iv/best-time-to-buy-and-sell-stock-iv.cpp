class Solution {
public:
    int dp[1001][2][101];
    int h(int idx,int canBuy,int k,vector<int> &prices){
        if(idx>=prices.size() || k<0) return 0;
        if(dp[idx][canBuy][k]!=-1) return dp[idx][canBuy][k];
        if(canBuy){
            return dp[idx][canBuy][k]=max(-prices[idx]+h(idx+1,!canBuy,k,prices),h(idx+1,canBuy,k,prices));
        }else{
            return dp[idx][canBuy][k]=max(prices[idx]+h(idx+1,!canBuy,k-1,prices),h(idx+1,canBuy,k,prices));
        }
    }
    int maxProfit(int k,vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return h(0,1,k-1,prices);
    }
};
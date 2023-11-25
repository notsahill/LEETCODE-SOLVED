class Solution {
public:
    int dp[2000][2000];
    int h(int idx,int upto,vector<int> &prices)
    {
        int n=prices.size();
        upto=min(upto,n);
        if(idx==n) return 0;
        if(idx>n) return 1e9;
        if(idx>upto) return prices[idx] +h(idx+1,idx+idx+1,prices);
        if(dp[idx][upto]!=-1) return dp[idx][upto];
        int buy=prices[idx]+ h(idx+1,idx+idx+1,prices);
        int not_buy=1e9;
        if(idx<=upto) not_buy= h(idx+1,upto,prices);
        
        return dp[idx][upto]= min(buy,not_buy);
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return prices[0]+h(1,1,prices);
    }
};
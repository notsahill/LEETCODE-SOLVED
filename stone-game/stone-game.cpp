class Solution {
public: 
    int dp[501][501];
    int helper(vector<int> piles,int l,int h)
    {
      int n=piles.size();
      if(l>h) return 0;
      if(l==n-1) return piles[l];
      if(h==0) return piles[h];
      if(dp[l][h]!=-1) return dp[l][h];
      return dp[l][h]=max(piles[l]+helper(piles,l+1,h-1),piles[h]+helper(piles,l+1,h-1));

    }
    bool stoneGame(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int sum=0;
        accumulate(piles.begin(),piles.end(),sum);
        int q=helper(piles,0,n-1);
        return q>sum-q;
    }
};
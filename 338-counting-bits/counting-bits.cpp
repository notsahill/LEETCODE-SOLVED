class Solution {
public:
    int h(int i,vector<int> &dp){
        if(i==0) return 0;
        if(i==1) return 1;
        int partial_ans=h(i/2,dp);
        if(i%2==1) partial_ans++;
        return dp[i]=partial_ans;
    }
    vector<int> countBits(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        for(int i=n;i>=0;i--){
            dp[i]=h(i,dp);
        }
        return dp;
    }
};
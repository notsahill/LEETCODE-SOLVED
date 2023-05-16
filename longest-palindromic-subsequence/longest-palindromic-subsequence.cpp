class Solution {
public:
    int helper(int l,int h,string &s, vector<vector<int>> &dp)
    {
        if(l>h) return 0;
        if(l==h) return 1;
        if(dp[l][h]!=-1) return dp[l][h];
        if(s[l]==s[h])
        {
            return 2+helper(l+1,h-1,s,dp);
        }
        int a=helper(l+1,h,s,dp);
        int b=helper(l,h-1,s,dp);
        return dp[l][h]=max(a,b);
    }
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return helper(0,n-1,s,dp);
    }
};
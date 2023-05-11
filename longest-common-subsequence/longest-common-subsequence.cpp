class Solution {
public:
    int helper(string &t1,string &t2,int i,int j,vector<vector<int>> &dp)
    {
        if(i==t1.size()||j==t2.size()) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]) return 1+ helper(t1,t2,i+1,j+1,dp);
        int a=helper(t1,t2,i,j+1,dp);
        int b=helper(t1,t2,i+1,j,dp);
        return dp[i][j]=max(a,b);
    }
    int longestCommonSubsequence(string t1, string t2) 
    {
        int m=t1.size(),n=t2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(t1,t2,0,0,dp);
    }
};
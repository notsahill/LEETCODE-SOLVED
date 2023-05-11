class Solution {
public:
    int helper(vector<int>& n1, vector<int>& n2,int i,int j,vector<vector<int>> &dp)
    {
        if(i==n1.size()||j==n2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(n1[i]==n2[j]) return 1+helper(n1,n2,i+1,j+1,dp);
        int a=helper(n1,n2,i,j+1,dp);
        int b=helper(n1,n2,i+1,j,dp);
        return dp[i][j]=max(a,b);
    }
    int maxUncrossedLines(vector<int>& n1, vector<int>& n2) 
    {
        int m=n1.size(),n=n2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(n1,n2,0,0,dp);
    }
};
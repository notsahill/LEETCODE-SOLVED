class Solution {
public:
    int helper(int i,string &s1,int j,string &s2,vector<vector<int>> &dp)
    {
        if(i==s1.size())
        {
            int ans=0;
            while(j<s2.size())
            {
                ans+=(int)s2[j];
                j++;
            }
            return ans;
        }
        if(j==s2.size())
        {
            int ans=0;
            while(i<s1.size())
            {
                ans+=(int)s1[i];
                i++;
            }
            return ans;
        }
        
        if(s1[i]==s2[j]) return helper(i+1,s1,j+1,s2,dp);
        if(dp[i][j]!=-1) return dp[i][j];
        int x= (int)s1[i] + helper(i+1,s1,j,s2,dp);
        int y=(int)s2[j] + helper(i,s1,j+1,s2,dp);
        return dp[i][j]=min(x,y);
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int> (s2.size(),-1));
        return helper(0,s1,0,s2,dp);
    }
};
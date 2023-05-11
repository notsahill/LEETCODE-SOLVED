class Solution {
public: 
    // int helper(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    // {
    //     int m=s1.size(),n=s2.size();
    //     if(i==m) return n-j;
    //     if(j==n) return m-i;
    //     int ans=0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j]) return helper(i+1,j+1,s1,s2,dp);
    //     else
    //     {
    //         int ins=helper(i+1,j,s1,s2,dp);
    //         int del=helper(i,j+1,s1,s2,dp);
    //         int rep=helper(i+1,j+1,s1,s2,dp);
    //         ans+=1+min(ins,min(del,rep));
    //     }
    //     return dp[i][j]=ans;
    // }
    int minDistance(string w1, string w2) 
    {
        int m=w1.size(),n=w2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        // return helper(0,0,w1,w2,dp);    
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=0;i<=n;i++) dp[0][i]=i;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(w1[i-1]==w2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
};
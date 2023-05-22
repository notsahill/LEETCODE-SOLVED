class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n));
        bool flag=0;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]=='1') flag=1;
            dp[i][0]=matrix[i][0]-'0';
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]=='1') flag=1;
            dp[0][i]=matrix[0][i]-'0';
        }
        int mx=0;
        if(flag) mx++;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='0') dp[i][j]=0;
                else
                {
                    int a=dp[i][j-1],b=dp[i-1][j-1],c=dp[i-1][j];
                    dp[i][j]=min(a,min(b,c))+1;
                    mx=max(mx,dp[i][j]);
                }
            }
        }
        return mx*mx;
    }
};
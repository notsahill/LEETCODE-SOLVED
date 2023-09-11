class Solution {
public:
    int mx=0;
    int di[4]={1,0,-1,0};
    int dj[4]={0,1,0,-1};
    int m,n;
    int dfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        int mx=0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++)
        {
            int x=i+di[k];
            int y=j+dj[k];
            if(x<0 or y<0 or x>=m or y>=n or mat[x][y]<=mat[i][j]) continue;
            int val=1+dfs(x,y,mat,dp);
            mx=max(mx,val);
        }
        return dp[i][j]=mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int mx=0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(dp[i][j]==-1) dfs(i,j,matrix,dp);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               mx=max(mx,dp[i][j]);
            }
        }


        return mx+1;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0)),ans(m,vector<int> (n,0));
        queue<vector<int>> q; //{i,j,dist}
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        while(q.size())
        {
            int i=q.front()[0],j=q.front()[1],dist=q.front()[2];
            q.pop();
            ans[i][j]=dist;
            if(i-1>=0 and !vis[i-1][j])
            {
                q.push({i-1,j,dist+1});
                vis[i-1][j]=1;
            }
            if(j-1>=0 and !vis[i][j-1])
            {
                q.push({i,j-1,dist+1});
                vis[i][j-1]=1;
            }
            if(i+1<m and !vis[i+1][j])
            {
                q.push({i+1,j,dist+1});
                vis[i+1][j]=1;
            }
            if(j+1<n and !vis[i][j+1])
            {
                q.push({i,j+1,dist+1});
                vis[i][j+1]=1;
            }
        }
        return ans;
    }
};
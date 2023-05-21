class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j,queue<pair<int,int>> &q)
    {
        int n=grid.size();
        vis[i][j]=1;
        q.push({i,j});
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 and ny>=0 and nx<n and ny< n)
            {
                if(grid[nx][ny]==1 and !vis[nx][ny]) dfs(grid,vis,nx,ny,q);
            }
        }
        // if(i-1>=0&&!vis[i-1][j]&&grid[i-1][j]==1) dfs(grid,vis,i-1,j,q);
        // if(j-1>=0&&!vis[i][j-1]&&grid[i][j-1]==1) dfs(grid,vis,i,j-1,q);
        // if(i+1<n&&!vis[i+1][j]&&grid[i+1][j]==1) dfs(grid,vis,i+1,j,q);
        // if(j+1<n&&!vis[i][j+1]&&grid[i][j+1]==1) dfs(grid,vis,i,j+1,q);
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (n,0));
        bool flag=0,found =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,vis,i,j,q);
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        int dist=0;
        while(q.size())
        {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                pair<int ,int> curr=q.front();
                q.pop();
                for(int c=0;c<4;c++)
                {
                    int i=curr.first+dx[c];
                    int j=curr.second+dy[c];
                    if(i>=0 and i<n and j>=0 and j<n and !vis[i][j])
                    {
                        if(grid[i][j]==1) return dist;
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }        
            }
            dist++;
        }
        return 0;
    }
};
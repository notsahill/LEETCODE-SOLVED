class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int> (n,0));
        if(grid[0][0]==0) 
        {
            q.push({{0,0},1});
            vis[0][0]=1;
        }
        while(q.size())
        {
            int x=q.front().first.first,y=q.front().first.second,d=q.front().second;
            vis[x][y]=1;
                if(x==n-1 and y==n-1) return d;
                q.pop();
                if(x-1>=0 and grid[x-1][y]==0 and !vis[x-1][y]) 
                {
                    q.push({{x-1,y},d+1}); 
                    vis[x-1][y]=1;
                }
                if(y-1>=0 and grid[x][y-1]==0 and !vis[x][y-1]) 
                {
                    q.push({{x,y-1},d+1});
                    vis[x][y-1]=1;
                }
                if(x+1<n and grid[x+1][y]==0 and !vis[x+1][y]) 
                {
                    q.push({{x+1,y},d+1}); 
                    vis[x+1][y]=1;
                }
                if(y+1<n and grid[x][y+1]==0 and !vis[x][y+1]) 
                {
                    q.push({{x,y+1},d+1});
                    vis[x][y+1]=1;
                }
                if(x-1>=0 and y-1>=0 and grid[x-1][y-1]==0 and !vis[x-1][y-1]) 
                {
                    q.push({{x-1,y-1},d+1}); 
                    vis[x-1][y-1]=1;
                }
                if(x-1>=0 and y+1<n and grid[x-1][y+1]==0 and !vis[x-1][y+1]) 
                {
                    q.push({{x-1,y+1},d+1});
                    vis[x-1][y+1]=1;
                }
                if(x+1<n and y-1>=0 and grid[x+1][y-1]==0 and !vis[x+1][y-1]) 
                {
                    q.push({{x+1,y-1},d+1});
                    vis[x+1][y-1]=1;
                }
                if(x+1<n and y+1<n and grid[x+1][y+1]==0 and !vis[x+1][y+1]) 
                {
                    q.push({{x+1,y+1},d+1});  
                    vis[x+1][y+1]=1;
                }       
        }
        return -1;
    }
};
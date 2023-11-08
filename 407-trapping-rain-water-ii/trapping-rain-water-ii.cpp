class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int trapRainWater(vector<vector<int>>& hm) {
        priority_queue<p,vector<p> ,greater<p>> pq;
        int m=hm.size(),n=hm[0].size(),c=0;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            pq.push({hm[0][i],{0,i}});
            pq.push({hm[m-1][i],{m-1,i}});
            vis[0][i]=1,vis[m-1][i]=1;
        }
        for(int i=1;i<m-1;i++)
        {
            pq.push({hm[i][0],{i,0}});
            pq.push({hm[i][n-1],{i,n-1}});
            vis[i][n-1]=1,vis[i][0]=1;
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(pq.size())
        {
            int ht=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=m or ny<0 or ny>=n or vis[nx][ny]) continue;
                int diff=max(0,ht-hm[nx][ny]);
                c+=diff;
                pq.push({hm[nx][ny]+diff,{nx,ny}});
                vis[nx][ny]=1;
            }
        }
        return c;
    }
};
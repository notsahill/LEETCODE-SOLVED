class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        unordered_map<int,vector<int>> r,c;
        int ans=0,n=grid.size();
        for(int i=0;i<n;i++)
        {
            vector<int> row;
            for(int j=0;j<n;j++)
            {
                row.push_back(grid[i][j]);
            }
            r[i]=row;
        }
        for(int j=0;j<n;j++)
        {
            vector<int> col;
            for(int i=0;i<n;i++)
            {
                col.push_back(grid[i][j]);
            }
            c[j]=col;
        }
        for(auto row:r)
        {
            int idx=row.first;
            vector<int> rw=row.second;
            for(auto col:c)
            {
                int idx1=col.first;
                vector<int> cl=col.second;
                if(rw==cl) ans++;
            }
        }
        return ans;
    }
};
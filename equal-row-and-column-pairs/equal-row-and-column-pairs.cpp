class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        unordered_map<int,vector<int>> r,c;
        int ans=0,n=grid.size();
        for(int j=0;j<n;j++)
        {
            vector<int> row=grid[j];
            r[j]=row;
            vector<int> col;
            for(int i=0;i<n;i++)
            {
                col.push_back(grid[i][j]);
            }
            c[j]=col;
        }
        for(auto row:r)
        {
            for(auto col:c)
            {
                if(row.second==col.second) ans++;
            }
        }
        return ans;
    }
};
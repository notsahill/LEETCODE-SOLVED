class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        map<int,int> mpRow,mpCol; //for counting ones
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    mpRow[i]++;
                    mpCol[j]++;
                }
            }
        }
        vector<vector<int>> diff(m,vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=mpRow[i]+mpCol[j]-(n-mpRow[i])-(m-mpCol[j]);
            }
        }
        return diff;
    }
};
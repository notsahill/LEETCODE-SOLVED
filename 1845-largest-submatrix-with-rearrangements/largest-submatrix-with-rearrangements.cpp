class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]!=0) matrix[i][j]+=matrix[i-1][j];
            }
            vector<int> row=matrix[i];
            sort(row.begin(),row.end());
            for(int i=0;i<n;i++)
            {
                area=max(area, row[i]*(n-1-i+1));
            }
        }
        return area;
    }
};
class Solution {
public:
    void transpose(vector<vector<int>> &mat, int n, int m)
    {
        for(int i=0;i<m-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& mat) 
    {
        int n=mat.size(),m=mat[0].size();
        transpose(mat,n,m);
        for(int i=0;i<mat.size();i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};
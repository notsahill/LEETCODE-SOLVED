class Solution {
public:
    bool check(int i,int j,vector<vector<int>> &mat,int m,int n){
        for(int k=0;k<m;k++){
            if(k==i) continue;
            if(mat[k][j]==1) return false;
        }
        for(int k=0;k<n;k++){
            if(k==j) continue;
            if(mat[i][k]==1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int c=0;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) continue;
                if(check(i,j,mat,m,n)) c++;
            }
        }
        return c;
    }
};
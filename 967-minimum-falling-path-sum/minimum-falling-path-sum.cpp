class Solution {
public:
    int dp[101][101];
    bool isValid(int i,int j,int& n){
        return !(i<0 || j<0 || i>=n || j>=n);
    }
    int h(int i,int j,vector<vector<int>> &mat){
        int n=mat.size();
        if(i<0 or j<0 or i>=n or j>=n) return 1e9;
        if(i==0) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=1e9,b=1e9,c=1e9;
        if(isValid(i-1,j-1,n)) a=h(i-1,j-1,mat);
        if(isValid(i-1,j,n)) b=h(i-1,j,mat);
        if(isValid(i-1,j+1,n)) c=h(i-1,j+1,mat);
        return dp[i][j]=min(a,min(b,c))+mat[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       memset(dp,-1,sizeof(dp));
       int mn=1e9;
       bool f=0;
       for(int i=0;i<n;i++){
           if(matrix[0][i]!=0){
                f=1;
                break;
           }
       }
       if(!f) return -1;
       for(int i=0;i<n;i++){
           mn=min(mn,h(n-1,i,matrix));
       }
       return mn;
    }
};
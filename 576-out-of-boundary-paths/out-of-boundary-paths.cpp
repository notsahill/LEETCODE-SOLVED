class Solution {
public:
    int dp[52][52][52];
    int h(int i,int j,int &m, int &n, int move){
        int MOD=1e9+7;
        if((i<0 or j<0 or i>=m or j>=n) and move>=0 ) return 1;
        if(move<0) return 0;
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        long long a=h(i-1,j,m,n,move-1)%MOD;
        long long b=h(i+1,j,m,n,move-1)%MOD;
        long long c=h(i,j-1,m,n,move-1)%MOD;
        long long d=h(i,j+1,m,n,move-1)%MOD;
        long long ans=(a+b+c+d)%MOD;
        return dp[i][j][move]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return h(startRow,startColumn,m,n,maxMove);
    }
};
class Solution {
public:
    int h(int i,int j,vector<int> &values,vector<vector<int>> &dp){
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=1e9;
        for(int k=i+1;k<j;k++){
            int val=h(i,k,values,dp)+h(k,j,values,dp)+values[i]*values[j]*values[k];
            mn=min(mn,val);
        }
        return dp[i][j]=mn;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return h(0,n-1,values,dp);
    }
};
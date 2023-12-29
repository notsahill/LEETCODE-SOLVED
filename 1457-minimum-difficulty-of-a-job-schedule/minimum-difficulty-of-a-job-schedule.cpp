class Solution {
public:
    int dp[301][11];
    int h(int idx,int n,vector<int>& jobDifficulty, int d){
        if(d==1){
            int mx=jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                mx=max(mx,jobDifficulty[i]);
            }
            return mx;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int mx=jobDifficulty[idx],ans=1e9;
        for(int i=idx;i<=n-d;i++){
            mx=max(mx,jobDifficulty[i]);
            int temp=h(i+1,n,jobDifficulty,d-1)+mx;
            ans=min(ans,temp);
        }
        return dp[idx][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()) return -1;
        memset(dp,-1,sizeof(dp));
        return h(0,jobDifficulty.size(),jobDifficulty,d);
    }
};
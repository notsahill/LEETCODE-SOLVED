class Solution {
public:
    int h(int idx,vector<int> &arr,int &k,vector<int> &dp){
        if(idx>=arr.size()) return 0;
        int mx=-1e9,ans,n=arr.size();
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<min(idx+k,n);i++){
            int terms=i-idx+1;
            mx=max(mx,arr[i]);
            int val=h(i+1,arr,k,dp)+terms*mx;
            ans=max(ans,val);
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return h(0,arr,k,dp);
    }
};
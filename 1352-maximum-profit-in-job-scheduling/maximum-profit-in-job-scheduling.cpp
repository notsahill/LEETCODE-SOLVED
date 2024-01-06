class Solution {
public:
    int nextIndex(vector<vector<int>> &mp,int val,int idx){
        int l=idx,h=mp.size()-1;
        int ans=mp.size();
        while(l<=h){
            int mid=(l+h)>>1;
            if(mp[mid][0]>=val){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    int h(int i,vector<vector<int>> &mp,vector<int> &dp){
        int n=mp.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int exc=h(i+1,mp,dp);
        int possibleNextIndex=nextIndex(mp,mp[i][1],i);
        int inc=mp[i][2]+h(possibleNextIndex,mp,dp);
        return dp[i]=max(inc,exc);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n=startTime.size();
        vector<vector<int>> mp(n, vector<int> (3));
        for(int i=0;i<n;i++){
            mp[i]={startTime[i],endTime[i],profit[i]}; //{s,e,p}
        }
        sort(mp.begin(),mp.end());
        vector<int> dp(n+1,-1);
        return h(0,mp,dp);
    }
};
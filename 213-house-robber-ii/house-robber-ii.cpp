class Solution {
public:
    int h(int idx,int end, vector<int> &nums,vector<int> &dp)
    {
        if(idx>end) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int not_pick=h(idx+1,end,nums,dp);
        int pick=nums[idx]+h(idx+2,end,nums,dp);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n+1,-1),dp2(n+1,-1);
        int a= h(0,n-2,nums,dp1);
        int b= h(1,n-1,nums,dp2);
        return max(a,b);
    }
};
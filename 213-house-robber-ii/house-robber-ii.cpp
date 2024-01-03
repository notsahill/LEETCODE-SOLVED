class Solution {
public:
    int h(int i,int j,vector<int> &nums,vector<int> &dp){
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=h(i+2,j,nums,dp)+nums[i];
        int not_pick=h(i+1,j,nums,dp);
        return dp[i]=max(pick,not_pick); 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return max(nums[0],nums[n-1]);
        vector<int> dp(n+1,-1),dp1(n+1,-1);
        int option1=h(0,n-2,nums,dp);
        int option2=h(1,n-1,nums,dp1);
        return max(option1,option2);
    }
};
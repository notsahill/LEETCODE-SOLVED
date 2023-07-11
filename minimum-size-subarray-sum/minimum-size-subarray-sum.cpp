class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mn=INT_MAX;
        int i=0,n=nums.size(),j=0;
        long sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                mn=min(mn,j-i+1);
                sum=sum-nums[i];
                i++;
                if(sum>=target) mn=min(mn,j-i+1);
            }
            j++;
        }
        if(mn==INT_MAX) return 0;
        return mn;
    }
};
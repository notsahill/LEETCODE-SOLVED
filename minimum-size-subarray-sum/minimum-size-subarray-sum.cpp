class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,mn=INT_MAX,sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                mn=min(mn,j-i+1);
                sum=sum-nums[i];
                i++;            
            }
            j++;
        }
        if(mn==INT_MAX) return 0;
        return mn;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size(),mn=1e9,sum=0;
        while(j<n){
            sum+=nums[j];
            if(sum>=target) mn=min(mn,j-i+1);
            while(sum>=target and i<j){
                sum-=nums[i];
                i++;
                if(sum>=target) mn=min(mn,j-i+1);
            }
            j++;
        }
        return mn==1e9?0:mn;
    }
};
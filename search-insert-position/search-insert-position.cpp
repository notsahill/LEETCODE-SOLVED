class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n=nums.size(),l=0,h=n-1,ans=n;
        while(l<=h)
        {
            int mid=(l+h)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=target)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
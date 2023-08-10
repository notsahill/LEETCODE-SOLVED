class Solution {
public:
    int pivot(vector<int> &nums)
    {
        int l=0,h=nums.size()-1;
        while(l<h)
        {
            while(l<h and nums[l]==nums[l+1]) l++;
            while(l<h and nums[h]==nums[h-1]) h--;
            int mid=(l+h)>>1;
            if(nums[mid]>nums[h]) l=mid+1;
            else h=mid;
        }
        return l;
    }
    int findMin(vector<int>& nums) {
        int pvt=pivot(nums);
        return min(nums[0],nums[pvt]);
    }
};
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
    int bs(vector<int> &nums,int k,int l,int h)
    {
        while(l<=h)
        {
            int mid=(l+h)>>1;
            if(nums[mid]==k) return 1;
            if(nums[mid]>k) h=mid-1;
            else l=mid+1;
        }
        return 0;
    }
    bool search(vector<int>& nums, int target) {
        int pvt=pivot(nums);
        int x=bs(nums,target,0,pvt-1);
        if(x) return x;
        return bs(nums,target,pvt,nums.size()-1);
    }
};
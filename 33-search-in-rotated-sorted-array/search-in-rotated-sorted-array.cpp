class Solution {
public:
    int pivot(vector<int> &nums)
    {
        int l=0,h=nums.size()-1;
        while(l<h)
        {
            int mid=(l+h)>>1;
            if(nums[mid]>nums[h])
            {
                l=mid+1;
            }
            else h=mid;
        }
        return l;
    }
    int bs(vector<int> &nums,int k,int l,int h)
    {
        while(l<=h)
        {
            int mid=(l+h)>>1;
            if(nums[mid]==k) return mid;
            if(nums[mid]>k) h=h-1;
            else l=l+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pvt= pivot(nums);
        int x=bs(nums,target,0,pvt-1);
        if(x!=-1) return x;
        return bs(nums,target,pvt,nums.size()-1);
    }
};
class Solution {
public:
    int f(int l,int h,vector<int> &nums,int target)
    {
        if(l>h) return -1;
        int mid=(l+h)>>1;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) return f(mid+1,h,nums,target);
        return f(l,mid-1,nums,target);
    }
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        // int low=0,high=n-1;
        // while(low<=high)
        // {
        //     int mid=(low+high)>>1;
        //     if(nums[mid]==target) return mid;
        //     else if(target>nums[mid]) low=mid+1;
        //     else high=mid-1;
        // }
        // return -1;
        return f(0,n-1,nums,target);
    }
};
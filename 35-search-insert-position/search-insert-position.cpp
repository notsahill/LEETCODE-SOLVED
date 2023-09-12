class Solution {
public:
    int h(int i,int j,vector<int> &nums,int target)
    {
        if(i>j) return -(i+1);
        
        int mid=(i+j)>>1;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return h(mid+1,j,nums,target);
        return h(i,mid-1,nums,target);
    }
    int searchInsert(vector<int>& nums, int target)
    {
        int n=nums.size();
        int x=h(0,n-1,nums,target);
        return x>=0? x : -(x)-1;
    }
};
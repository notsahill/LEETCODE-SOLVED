class Solution {
public:
    int h(int i,int j,int &val,vector<int> &nums){
        while(i<=j){
            int mid=(i+j)>>1;
            if(nums[mid]==val) return mid;
            else if(nums[mid]>val) j=mid-1;
            else i=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return h(0,n-1,target,nums);
    }
};
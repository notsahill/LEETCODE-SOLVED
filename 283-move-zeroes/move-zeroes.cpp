class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ip=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) swap(nums[ip++],nums[i]);
        }
    }
};
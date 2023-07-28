class Solution {
public:
    int helper(vector<int> &nums,int k)
    {
        int n=nums.size(),c=0,i=0,j=0;
        unordered_map<int,int> mp;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            c+=j-i+1;
            j++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};
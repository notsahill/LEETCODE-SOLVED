class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int start=nums[0][0],end=nums[0][1];
        ans+=end-start+1;
        for(int i=0;i<nums.size();i++)
        {
            start=max(end,nums[i][0]);
            if(start==end) ans--;
            end=max(end,nums[i][1]);
            ans+=end-start+1;
        }
        return ans;
    }
};
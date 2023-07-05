class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int c=0;
        int mx=INT_MIN,idx=-1;
        bool flag=0;
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==1)
            {
                c++;
                mx=max(c,mx);
                i++;
            }
            else if(nums[i]==0 and flag==0)
            {
                flag=1;
                idx=i;
                i++;
            }
            else
            {
                flag=0;
                c=0;
                i=idx+1;
            }
        }
        if(c==nums.size()) return c-1;
        if(mx==INT_MIN) return 0;
        return mx;
    }
};
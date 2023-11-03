class Solution {
public:
    vector<string> buildArray(vector<int>& nums, int n) 
    {
        vector<string> ans;
        int j=0;
        for(int i=1;i<=n&&j<nums.size();i++)
        {
            if(nums[j]==i)
            {
                ans.push_back("Push");
                j++;
                continue;

            }    
             ans.push_back("Push");
             ans.push_back("Pop");
            
        }
        return ans;
    }
};
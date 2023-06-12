class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        int i=0;
        while(i<nums.size())
        {
            int j=i;
            string s="";
            
            while(j<nums.size()-1 and nums[j+1]==nums[j]+1) j++;
            if(j>i) s=to_string(nums[i])+"->"+to_string(nums[j]);
            else s=to_string(nums[i]);
            ans.push_back(s);
            i=j+1;
        }
        return ans;
    }
};
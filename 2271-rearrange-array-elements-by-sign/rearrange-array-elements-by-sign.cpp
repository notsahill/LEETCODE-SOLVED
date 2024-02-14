class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> positive;
        vector<int> negative;
        vector<int> s;
        int key=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==1) s.push_back(negative[i/2]);
            else s.push_back(positive[i/2]);
        }
        return s;
    }
};
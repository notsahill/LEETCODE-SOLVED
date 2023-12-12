class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                mx=max(mx,(nums[i]-1)*(nums[j]-1));
            }
        }
        return mx;
    }
};
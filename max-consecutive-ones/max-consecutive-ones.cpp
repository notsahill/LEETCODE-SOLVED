class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int c=0,mx=0;
        for(auto a:nums)
        {
            if(a==1)
            {
                c++;
                mx=max(mx,c);
            }
            else c=0;
        }
        return mx;
    }
};
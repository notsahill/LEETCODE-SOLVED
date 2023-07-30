class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int sz=(int)s.size(),n=nums.size(),c=0;
        set<int> s1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                s1.insert(nums[j]);
                if(s1.size()==sz) c++;
            }
            s1.clear();
        }
        return c;
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int mx=-1e9,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int x=nums[i],y=nums[j];
                if(abs(x-y)<=min(x,y)) mx=max(mx,x^y);
            }
        }
        return mx;
    }
};
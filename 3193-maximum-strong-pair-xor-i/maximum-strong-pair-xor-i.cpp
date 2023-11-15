class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int mx=-1e9,n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=nums[i],y=nums[j];
                if(abs(x-y)<=min(x,y)) mx=max(mx,x^y);
            }
        }
        return mx;
    }
};
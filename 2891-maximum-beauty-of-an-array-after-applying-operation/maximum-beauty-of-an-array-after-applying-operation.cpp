class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int mx=0,n=nums.size(),l=0,h=0;
        sort(nums.begin(),nums.end());
        while(h<n)
        {
            if(nums[h]-nums[l]>2*k) l=l+1;
            else
            {
                mx=max(mx,h-l+1);
            }
            h++;
        }
        return mx;
    }
};
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mx=nums[n-1],mn=nums[0],score=mx-mn;
        for(int i=1;i<n;i++)
        {
            mx=max(nums[n-1]-k,nums[i-1]+k);
            mn=min(nums[0]+k,nums[i]-k);
            cout<<mx<<" "<<mn<<endl;
            score=min(score,mx-mn);
        }
        return score;
    }
};
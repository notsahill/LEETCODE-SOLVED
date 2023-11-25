class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n),ps(n),ss(n);
        ps[0]=nums[0];
        ss[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            ps[i]=ps[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            ss[i]=ss[i+1]+nums[i];
        }

        for(int i=0;i<n;i++)
        {
            ans[i]= (nums[i]*i-(ps[i]-nums[i]))+((ss[i]-nums[i])-nums[i]*(n-i-1));
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(k==0) return nums;
        vector<int> ans(n,-1);
        if(2*k+1>n) return ans;
        long long sum=0;
        int left=0,right=2*k,i=k;
        for(int i=left;i<=right;i++)
        {
            sum+=nums[i];
        }
        ans[i]=sum/(2*k +1);
        i++;
        right++;
        while(right<n)
        {
            sum+=nums[right]-nums[left];
            ans[i]=sum/(2*k +1);
            right++,left++,i++;
        }
        return ans;
    }
};
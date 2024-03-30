class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=0,i=0,j=0,n=nums.size(),mxC=0;
        for(auto num:nums){
            mx=max(mx,num);
        }
        long long ans=0;
        while(j<n){
            if(nums[j]==mx) mxC++;
            while(mxC>=k){
                ans+=n-j;
                if(nums[i]==mx) mxC--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
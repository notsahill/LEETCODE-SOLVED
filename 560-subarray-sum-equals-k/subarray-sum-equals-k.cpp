class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),c=0;
        long long sum=0;
        unordered_map<int,int> mp;
        mp[sum]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int reqd=sum-k;
            if(mp[reqd]>0) c+=mp[reqd];
            mp[sum]++;
        }
        return c;
    }
};
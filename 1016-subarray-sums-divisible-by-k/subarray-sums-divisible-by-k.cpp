class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int c=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        long long sum=0;
        mp[0]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(mp[rem]>0) c+=mp[rem];
            mp[rem]++;
        }
        return c;
    }
};
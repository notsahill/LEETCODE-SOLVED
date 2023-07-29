class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c=0,n=nums.size();
        long long sum=0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem=rem+k;
            if(mp[rem]>0) c+=mp[rem];
            mp[rem]++;
        }
        return c;
    }
};
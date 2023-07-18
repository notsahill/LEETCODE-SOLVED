class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),c=0,sum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto num:nums)
        {
            sum+=num;
            int reqd=sum-k;
            c+=mp[reqd];
            mp[sum]++;
        }
        // if(k==0)
        return c;
    }
};
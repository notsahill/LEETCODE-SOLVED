class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n=nums.size();
        map<long long,int> mp;
        long long sum=0;
        mp[sum]++;
        int c=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            int reqd=sum-k;
            if(mp[reqd]>0) c+=mp[reqd];
            mp[sum]++;
        }
        return c;
    }
};
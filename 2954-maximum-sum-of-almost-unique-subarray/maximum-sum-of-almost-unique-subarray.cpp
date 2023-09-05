class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum=0,mx=0;
        int n=nums.size();
        if(n<k) return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()>=m) mx=max(mx,sum);
        int l=0,h=k;
        while(h<n)
        {
            //remove first
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            //now add last
            mp[nums[h]]++;
            //upade sum
            sum+=nums[h]-nums[l];
            //compare mx
            if(mp.size()>=m) mx=max(mx,sum);
            //increment l&h
            l++,h++;
        }
        return mx;
    }
};
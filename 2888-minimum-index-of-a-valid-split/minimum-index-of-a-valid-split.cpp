class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp1,mp2;
        // vector<int> occ(n);

        for(auto a:nums) mp1[a]++;
        for(int i=0;i<n;i++)
        {
            mp2[nums[i]]++;
            int s1=i+1,s2=n-i-1;
            int f1=mp2[nums[i]],f=mp1[nums[i]]-f1;
            if(2*f1>s1 and 2*f>s2) return i;
            // occ[i]=mp2[nums[i]];
        }
        return -1;
    }
};
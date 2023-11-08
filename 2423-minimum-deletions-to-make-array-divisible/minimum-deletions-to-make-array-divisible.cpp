class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsD) {
        int g=0,mn=1e9,c=0,n=nums.size();
        for(auto a:numsD) g=gcd(g,a);
        
        for(int i=0;i<n;i++)
        {
            if(g%nums[i]==0) mn=min(mn,nums[i]);
        }
        for(auto a:nums)
        {
            if(a<mn) c++;
        }
        // cout<<g<<" "<<mn<<" "<<c<<endl;
        return mn==1e9?-1:c;
    }
};
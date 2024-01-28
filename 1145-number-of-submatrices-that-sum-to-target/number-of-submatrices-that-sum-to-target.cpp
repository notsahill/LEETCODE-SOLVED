class Solution {
public:
    int subarraysum(vector<int>& nums, int k) {
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
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int ans=0;
        for(int i=0;i<mat.size();i++)
        {
            vector<int> sum(mat[0].size(),0);
            for(int j=i;j<mat.size();j++)
            {
               for(int k=0;k<mat[0].size();k++)
               {
                  sum[k]+=mat[j][k];
               }
               ans+=subarraysum(sum,target);
            }
        }
        return ans;
    }
};
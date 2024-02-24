class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(k>j){
                long long sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(nums[k]==nums[k+1] && k>j) k--;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        return ans;
    }
};
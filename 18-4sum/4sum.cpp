class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[l];
                    sum+=nums[k];
                    if(sum==target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++,l--;
                        while(nums[k]==nums[k-1] && k<l) k++;
                        while(nums[l]==nums[l+1] && k<l) l--;
                    }
                    else if(sum>target) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};
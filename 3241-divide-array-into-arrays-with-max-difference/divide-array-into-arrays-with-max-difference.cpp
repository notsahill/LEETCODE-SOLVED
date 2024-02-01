class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n%3!=0) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i+1]<=k and nums[i+1]-nums[i]<=k and nums[i+2]-nums[i]<=k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else return {};
        }
        return ans;
    }
};
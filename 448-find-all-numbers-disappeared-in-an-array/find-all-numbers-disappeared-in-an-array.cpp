class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,mp(n+1,0);
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
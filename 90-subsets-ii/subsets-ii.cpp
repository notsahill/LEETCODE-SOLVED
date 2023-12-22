class Solution {
public:
    set<vector<int>> s;
    void h(int i,int &n,vector<int> &temp,vector<int> &nums){
        if(i>=n){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        h(i+1,n,temp,nums);
        temp.pop_back();
        h(i+1,n,temp,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        h(0,n,temp,nums);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void h(int idx,int target,vector<int>& temp,vector<int>& candidates)
    {
        int n=candidates.size();
        if(idx==n)
        {
            if(target==0) ans.push_back(temp);
            return;
        }

        if(candidates[idx]<=target)
        {
            temp.push_back(candidates[idx]);
            h(idx,target-candidates[idx],temp,candidates);
            temp.pop_back();
        }
        h(idx+1,target,temp,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> temp;
       h(0,target,temp,candidates);
       return ans; 
    }
};
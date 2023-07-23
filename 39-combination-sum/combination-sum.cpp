class Solution {
public:
    vector<vector<int>> ans;
    void h(int idx,vector<int>& c, int target,vector<int>& temp)
    {
        int n=c.size();
        if(idx==n and target ==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx==n) return;
        if(c[idx]<=target)
        {
            temp.push_back(c[idx]);
            h(idx,c,target-c[idx],temp);
            temp.pop_back();
        }
        h(idx+1,c,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) 
    {
        vector<int> temp;
        h(0,c,target,temp);
        return ans;
    }
};
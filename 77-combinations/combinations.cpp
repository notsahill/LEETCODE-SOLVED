class Solution {
public:
    vector<vector<int>> ans;
    void h(int i,int n,int k,vector<int> &temp)
    { 
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i>n) return;
        temp.push_back(i);
        h(i+1,n,k-1,temp);
        temp.pop_back();
        h(i+1,n,k,temp);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        h(1,n,k,temp);
        return ans;
    }
};
class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n=pref.size();
        int rx=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=rx^pref[i];
            rx^=ans[i];
        }
        return ans;
    }
};
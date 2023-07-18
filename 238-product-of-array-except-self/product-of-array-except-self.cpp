class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) 
    {
        int l=n.size();
        int s[l],p[l];
        vector<int> ans(l-1);
        p[0]=n[0],s[l-1]=n[l-1];
        for(int i=1;i<l;i++)
        {
            p[i]=p[i-1]*n[i];
        }
        for(int i=l-2;i>=0;i--)
        {
            s[i]=s[i+1]*n[i];
        }
        ans[0]=s[1];
        for(int i=1;i<l-1;i++)
        {
            ans[i]=p[i-1]*s[i+1];
        }
        ans.push_back(p[l-2]);
        return ans;
    }
};
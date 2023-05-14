class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) 
    {
        int n=d.size();
        vector<int> o(n);
        o[0]=0;
        for(int i=1;i<n;i++)
        {
            o[i]=o[i-1]^d[i-1];
        }
        if(o[n-1]==d[n-1]) return true;
        return false;
    }
};
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mx=-1e9;
        for(int i=0;i<left.size();i++)
        {
            mx=max(mx,left[i]);
        }
        for(int i=0;i<right.size();i++)
        {
            mx=max(mx,n-right[i]);
        }
        return mx;
    }
};
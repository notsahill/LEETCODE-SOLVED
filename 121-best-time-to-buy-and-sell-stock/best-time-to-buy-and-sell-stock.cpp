class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int mn=INT_MAX;
        for(auto p:prices)
        {
            if(p<mn) mn=p;
            mx=max(mx,p-mn);
        }
        return mx;
    }
};
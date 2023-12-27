class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=1e9,mx=0;
        for(int i=0;i<prices.size();i++){
            mn=min(mn,prices[i]);
            mx=max(mx,prices[i]-mn);
        }
        return mx;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit=0,mnPrice=1e9;
        for(int price:prices){
            if(price<mnPrice) mnPrice=price;
            else{
                mxProfit=max(mxProfit,price-mnPrice);
            }
        }
        return mxProfit;
    }
};
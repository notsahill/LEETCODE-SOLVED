class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int alice=0,bob=0,me=0;
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int i=0,j=n-1;
        while(i<j)
        {
            alice+=piles[j];
            me+=piles[j-1];
            bob+=piles[i];
            i++;
            j-=2;
        }
        return me;
    }
};
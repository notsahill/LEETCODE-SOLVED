class Solution {
public:
    vector<int> numOfBurgers(int tS, int cS) 
    {
        if(tS%2!=0) return {};
        int t=tS/2;
        int x=t-cS;
        int y=cS-x;
        if(x<0 or y<0) return {};
        return {x,y};
    }
};
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int MOD=1e9+7;
        int mxH=horizontalCuts[0];
        int mxV=verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++)
        {
            mxH=max(mxH,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            mxV=max(mxV,verticalCuts[i]-verticalCuts[i-1]);
        }
        return (1LL*mxH*mxV)%MOD;
    }
};
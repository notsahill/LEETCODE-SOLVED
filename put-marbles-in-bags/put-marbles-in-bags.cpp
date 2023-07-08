class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> pairsum;
        for(int i=1;i<weights.size();i++)
        {
            pairsum.push_back(weights[i]+weights[i-1]);
        }
        long long mx=0,mn=0;
        sort(pairsum.begin(),pairsum.end());
        for(int i=0;i<k-1;i++)
        {
            mn+=pairsum[i];
            mx+=pairsum[pairsum.size()-1-i];
        }
        return mx-mn;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mn=INT_MAX;
        unordered_set<int> s;
        for(auto a:nums)
        {
            if(a<=0) continue;
            mn=min(mn,a);
            s.insert(a);
        }
        if(mn==INT_MAX or mn>1) return 1;
        while(1)
        {
            if(!s.count(mn)) return mn;
            mn++;
        }
        return -1;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto a:nums) mp[a]++;
        int ans=0;
        for(auto a:mp){
            if(a.second==1) return -1;
            ans+=a.second/3;
            if(a.second%3!=0) ans++;
        }
        return ans;
    }
};
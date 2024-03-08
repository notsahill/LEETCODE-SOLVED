class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        int mx=0,ans=0;
        for(auto num:nums){
            freq[num]++;
            if(freq[num]>mx){
                mx=freq[num];
                ans=mx;
            }
            else if(freq[num]==mx){
                ans+=mx;
            }
        }
        return ans;
    }
};
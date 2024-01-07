class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<long,int> mp[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-nums[j];
                int c=0;
                if(mp[j].find(diff)!=mp[j].end()) c=mp[j][diff];
                mp[i][diff]+=c+1;
                ans+=c;
            }
        }
        return ans;
    }
};
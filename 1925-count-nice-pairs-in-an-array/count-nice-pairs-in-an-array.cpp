class Solution {
public:
    int rev(int n)
    {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int ans=stoi(s);
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int MOD=1e9+7;
        int c=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]-=rev(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>0)
            {
                c=(c+mp[nums[i]])%MOD;
                mp[nums[i]]++;
            }
            else mp[nums[i]]++;
        }

        return c%MOD;
    }
};
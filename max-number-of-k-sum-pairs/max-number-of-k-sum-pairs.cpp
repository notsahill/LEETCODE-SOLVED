class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int e=nums[i];
            int reqd=k-e;
            if(m[reqd]>0) 
            {
                ans++;
                m[reqd]--;
            }
            else m[e]++;
        }
        return ans;
    }
};
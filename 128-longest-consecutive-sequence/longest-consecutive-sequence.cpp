class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int mx=0,c=0,n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(st.count(num-1)) continue;
            while(st.count(num)){
                num++;
                c++;
            }
            mx=max(mx,c);
            c=0;
        }
        return mx;
    }
};
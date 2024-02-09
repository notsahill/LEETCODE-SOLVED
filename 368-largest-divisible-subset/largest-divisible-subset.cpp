class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int last_chosen = 0;
        int mx = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }

                    if(dp[i] > mx) {
                        mx = dp[i];
                        last_chosen = i;
                    }
                }
            }
        }
        vector<int> result;
        while(last_chosen >= 0) {
            result.push_back(nums[last_chosen]);
            last_chosen = prev[last_chosen];
        }
        return result;
    }
};
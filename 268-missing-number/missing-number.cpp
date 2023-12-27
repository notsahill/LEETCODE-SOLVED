class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,expected_sum=(n*(n+1))/2;
        for(auto a:nums){
            sum+=a;
        }
        return expected_sum-sum;
    }
};
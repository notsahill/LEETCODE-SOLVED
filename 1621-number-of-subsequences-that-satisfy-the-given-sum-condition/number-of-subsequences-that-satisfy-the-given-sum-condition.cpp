class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size(),j=n-1,ans=0,MOD=1e9+7;
        vector<int> power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%MOD;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans=(ans%MOD+power[j-i])%MOD;
                i++;
            }
            else j--;
        }
        return ans;
    }
};
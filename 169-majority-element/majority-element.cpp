class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans){
                c++;
            }
            else{
                if(c>0){
                    c--;
                }
                else{
                    c=1;
                    ans=nums[i];
                }
            }
        }
        return ans;
    }
};
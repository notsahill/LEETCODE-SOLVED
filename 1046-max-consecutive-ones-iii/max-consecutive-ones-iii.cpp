class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,c=0,mx=0,n=nums.size();
        while(j<n)
        {
            if(nums[j]==0) c++;
            while(c>k)
            {
                if(nums[i]==0) c--;
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx=0.0,sum=0.0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        mx=sum;
        int l=0,h=k;
        while(h<nums.size())
        {
            sum+=nums[h++]-nums[l++];
            mx=max(mx,sum);
        }
        return mx/k;
    }
};
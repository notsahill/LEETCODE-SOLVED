class Solution {
public:
    int h(int i,int j,vector<int> &nums)
    {
        // if(i>=nums.size() or j<0 ) return 0;
        if(j<i) return 0;
        if(i==j) return nums[i];
        int x=h(i+2,j,nums);
        int y=h(i+1,j-1,nums);
        int a=min(x,y)+nums[i];
        x=h(i,j-2,nums);
        y=h(i+1,j-1,nums);
        int b=min(x,y)+nums[j];
        return max(a,b);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto a:nums) sum+=a;
        int fps=h(0,n-1,nums);
        return fps>=sum-fps;
    }
};
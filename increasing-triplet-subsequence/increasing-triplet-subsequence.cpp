class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int smallest=INT_MAX,mid=INT_MAX;
        for(auto a:nums)
        {
            if(a>smallest and a>mid) return true;
            if(a<smallest) smallest=a;
            else if(a>smallest and a<mid) mid=a;
        }
        return false;
    }
};
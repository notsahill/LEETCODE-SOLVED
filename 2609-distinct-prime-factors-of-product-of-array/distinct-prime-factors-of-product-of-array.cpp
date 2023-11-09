class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for(auto a:nums)
        {
            int j=2;
            while(a!=1)
            {
                if(a%j==0)
                {
                    a=a/j;
                    s.insert(j);
                }
                else j++;
            }
        }
        return (int)s.size();
    }
};
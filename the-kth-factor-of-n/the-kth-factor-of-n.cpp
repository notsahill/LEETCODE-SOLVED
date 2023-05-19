class Solution {
public:
    int kthFactor(int n, int k) 
    {
        // vector<vector<int>> sieve(n+1);
        for(int i=1;i<=n&&k>0;i++)
        {
            if(n%i==0) k--;
            if(k==0) return i;
        }
        return -1;
    }
};
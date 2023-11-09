class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int primes[1001];
        memset(primes,1,sizeof(primes));
        for(int i=2;i<=1000;i++)
        {
            if(primes[i])
            {
                for(int j=2*i;j<=1000;j+=i)
                {
                    primes[j]=0;
                }
            }
        }
        vector<int> v;
        for(int i=2;i<=1000;i++)
        {
            if(primes[i]) v.push_back(i);
        }
        set<int> s;
        for(auto a:nums)
        {
            int j=0;
            while(a!=1)
            {
                if(a%v[j]==0)
                {
                    a=a/v[j];
                    s.insert(v[j]);
                }
                else j++;
            }
        }
        return (int)s.size();
    }
};
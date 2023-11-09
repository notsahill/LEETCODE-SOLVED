class Solution {
public:
    int countHomogenous(string str) {
        int c=0,MOD=1e9+7,ans=0;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(i==0 or str[i]==str[i-1])
            {
                c++;
            }
            else c=1;
            ans=(ans+c)%MOD;
        }
        return ans%MOD;
    }
};
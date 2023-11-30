class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return n;
        vector<long long> f(31,0);
        f[0]=1;
        for(int i=1;i<=30;i++)
        {
            f[i]=2*f[i-1]+1;
        }
        int sign=1,result=0;

        for(int i=30;i>=0;i--)
        {
            int bit=((1<<i)&n);
            if(bit==0) continue;

            if(sign>0){
                result+=f[i];
            }else{
                result-=f[i];
            }
            sign*=-1;
        }
        return result;
    }
};
class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int cnt=0;
        while(a>0||b>0||c>0)
        {
            int b1=a&1;
            int b2=b&1;
            int b3=b1|b2;
            int c1=c&1;
            if(b3!=c1)
            {   
                cnt++;
                if(b1==1&&b2==1&&c1==0) cnt++;     
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return cnt;    
    }
};
class Solution {
public:
    double myPow(double x, long n) 
    {
        if(n==0) return 1.00;
        if(x==0) return 0.00;
        if(n<0) return (double) 1/myPow(x,-1*n);
        double pans=myPow(x,n/2);
        if(n%2==0) return pans*pans;
        return pans*pans*x;
    }
};
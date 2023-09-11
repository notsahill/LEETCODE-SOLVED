class Solution {
public:
    int h(int n)
    {
        
        if(n<=2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        int x= 3*h(n-3);
        int y=3*(n-3);
        return max(x,y);
    }
    int integerBreak(int n) {
        return h(n);
    }
};
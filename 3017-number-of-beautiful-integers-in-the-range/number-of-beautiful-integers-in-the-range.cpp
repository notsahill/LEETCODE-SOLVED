class Solution {
public:
    bool check(int num)
    {
        // int n=log10(num)+1;
        // if(n%2!=0) return 0;
        int ec=0,oc=0;
        while(num>0)
        {
            if(num%2==0) ec++;
            else oc++;
            num/=10;
        }
        return oc==ec;
    }
    int first_element(int low,int k)
    {
        if(low%k==0) return low;
        else
        {
            int rem=low%k;
            low+=k-rem;
            return low;
        }
        return -1;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int c=0;
        low=first_element(low,k);
        while(low<=high)
        {
            if(check(low)) c++;
            low+=k;
            if(low>=100000000) return c;
        }
        return c;
    }
};
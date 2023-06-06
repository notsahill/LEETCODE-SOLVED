class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        set<int> s;
        int mn=INT_MAX,mx=INT_MIN,n=arr.size();
        for(auto a:arr) 
        {
            s.insert(a);
            mn=min(mn,a);
            mx=max(mx,a);
        }
        int d=(mx-mn)/(n-1);
        if((mx-mn)%(n-1)!=0) return 0;
        for(int i=0;i<=n-1;i++)
        {
            if(!s.count(mn+(i)*d)) return 0;
        }
        return 1;
    }
};
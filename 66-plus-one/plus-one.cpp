class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> ans=digits;
        int n=digits.size(),carry,count=0;
        if(digits[n-1]<9)
        {
            ans[n-1]++;
            return ans;
        }
        int i=n-1;
        while(i>=0 and digits[i]==9)
        {
            ans[i]=0;
            count++;
            carry=1;
            i--;
        }
        if(i>=0)
        {
            ans[i]++;
            return ans;
        }
        if(i<0) ans.insert(ans.begin(),carry);
        return ans;
    }    
};
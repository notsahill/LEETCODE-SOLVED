class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            ans+='0';
            if(s[i]=='1') c++;
        }
        c--;
        ans[n-1]='1';
        int i=0;
        while(c--)
        {
            ans[i++]='1';
        }
        return ans;
    }
};
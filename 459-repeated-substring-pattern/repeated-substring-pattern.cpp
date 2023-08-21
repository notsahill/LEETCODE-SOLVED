class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int l=n/2;l>=1;l--)
        {
            if(n%l==0)
            {
                int x=n/l;
                string pattern=s.substr(0,l),temp="";
                while(x--)
                {
                    temp+=pattern;
                }
                if(temp==s) return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    void add(string &ans,string &s,int i,int j)
    {
        for(int k=i;k<j;k++)
        {
            ans+=s[k];
        }
    }
    string reverseWords(string s) 
    {
        int l=s.size()-1;
        string ans="";
        while(l>=0)
        {
            while(l>=0 and s[l]==' ') l--;
            int r=l;
            if(l<0) break;
            while(l>=0 and s[l]!=' ') l--;
            if(ans.size()==0) add(ans,s,l+1,r+1);
            else 
            {
                ans+=" ";
                add(ans,s,l+1,r+1);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> ans;
    void helper(string &s,int ob,int cb)
    {
        if(ob==0 and cb==0)
        {
            ans.push_back(s);
            return;
        }
        else if(ob==cb)
        {
            string s1=s;
            s1+="(";
            helper(s1,ob-1,cb);
        }
        else if(ob==0)
        {
            string s1=s;
            s1+=")";
            helper(s1,ob,cb-1);
        }
        else
        {
            string s1=s,s2=s;
            s1+="(";
            s2+=")";
            helper(s1,ob-1,cb);
            helper(s2,ob,cb-1);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        int ob=n,cb=n;
        string s;
        helper(s,ob,cb);
        return ans;
    }
};
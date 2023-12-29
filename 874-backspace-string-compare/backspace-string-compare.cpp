class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string t1="",t2="";
        for(auto a: s)
        {
            if(a!='#') t1+=a;
            else
            {
                if(t1.size()>=1) t1.pop_back();
            }
        }
        for(auto a: t)
        {
            if(a!='#') t2.push_back(a);
            else
            {
                if(t2.size()>=1) t2.pop_back();
            }
        }
        return t1==t2;
    }
};
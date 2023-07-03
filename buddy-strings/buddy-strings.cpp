class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.size()!=goal.size()) return 0;
        int c=0;
        char a=' ',b=' ';
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(a==' ' and b==' ' and s[i]!=goal[i])
            {
                c++;
                a=s[i];
                b=goal[i];
            }
            else if(a!=' ' and b!=' ' and s[i]!=goal[i])
            {
                c++;
                if(goal[i]!=a or s[i]!=b) 
                {
                    return false;
                }
            }
            else if(c>2) return 0;
        }
        if(c==2) return true;
        if(c==0)
        {
        for(auto x:mp)
            {
                if(x.second>=2) return true;
           }
        }
        return false;
    }
};
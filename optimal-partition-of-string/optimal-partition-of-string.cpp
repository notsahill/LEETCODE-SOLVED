class Solution {
public:
    int partitionString(string st) 
    {
        set<int> s;
        int c=1;
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            if(!s.count(st[i]))
            {
                s.insert(st[i]);
            }
            else
            {
                s.clear();
                c++;
                s.insert(st[i]);
            }
        }
        return c;
    }
};
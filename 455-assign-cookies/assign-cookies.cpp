class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0,j=0,c=0;
        while(j<s.size() and i<g.size())
        {
            if(s[j]>=g[i])
            {
                c++,i++,j++;
            }
            else 
            {
                j++;
            }
        }
        return c;
    }
};